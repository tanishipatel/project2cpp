#include <iostream>
#include <cstring>
using namespace std;

class Train
{
private:
    int trainNumber;
    char trainName[50];
    char source[50];
    char destination[50];
    char trainTime[10];

    static int trainCount;

public:

    // Default Constructor
    Train()
    {
        trainNumber = 0;
        trainName[0] = '\0';
        source[0] = '\0';
        destination[0] = '\0';
        trainTime[0] = '\0';

        trainCount++ ;
    }

    // Parameterized Constructor
    Train(int num, char name[], char src[],
          char dest[], char time[])
    {
        trainNumber=num;

        strcpy(trainName, name);
        strcpy(source, src);
        strcpy(destination, dest);
        strcpy(trainTime, time);

        trainCount++;
    }

    // Destructor
    ~Train()
    {
        trainCount--;
    }

    // Setters
    void setTrainNumber(int num)
    {
        trainNumber = num;
    }

    void setTrainName(char name[])
    {
        strcpy(trainName, name);
    }

    void setSource(char src[])
    {
        strcpy(source, src);
    }

    void setDestination(char dest[])
    {
        strcpy(destination, dest);
    }

    void setTrainTime(char time[])
    {
        strcpy(trainTime, time);
    }

    // Getters
    int getTrainNumber()
    {
        return trainNumber;
    }

    char* getTrainName()
    {
        return trainName;
    }

    char* getSource()
    {
        return source;
    }

    char* getDestination()
    {
        return destination;
    }

    char* getTrainTime()
    {
        return trainTime;
    }

    // Input Function
    void inputTrainDetails()
    {
        cout << "\nEnter Train Number: ";
        cin >> trainNumber;
        cin.ignore();

        cout << "Enter Train Name: ";
        cin.getline(trainName, 50);

        cout << "Enter Source: ";
        cin.getline(source, 50);

        cout << "Enter Destination: ";
        cin.getline(destination, 50);

        cout << "Enter Train Time: ";
        cin.getline(trainTime, 10);
    }

    // Display Function
    void displayTrainDetails()
    {
        cout << "\nTrain Number : " << trainNumber;
        cout << "\nTrain Name   : " << trainName;
        cout << "\nSource       : " << source;
        cout << "\nDestination  : " << destination;
        cout << "\nTrain Time   : " << trainTime;
        
    }

    static int getTrainCount()
    {
        return trainCount;
    }
};

int Train::trainCount = 0;

class RailwaySystem
{
private:
    Train trains[100];
    int totalTrains;

public:

    RailwaySystem()
    {
        totalTrains = 0;
    }

    void addTrain()
    {
        trains[totalTrains].inputTrainDetails();
        totalTrains++;
    }

    void displayAllTrains()
    {
        if(totalTrains == 0)
        {
            cout << "\nNo Records Found!";
            return;
        }

        for(int i = 0; i < totalTrains; i++)
        {
            trains[i].displayTrainDetails();
        }
    }

    void searchTrainByNumber(int number)
    {
        for(int i = 0; i < totalTrains; i++)
        {
            if(trains[i].getTrainNumber() == number)
            {
                trains[i].displayTrainDetails();
                return;
            }
        }

        cout << "\nTrain Not Found!";
    }
};

int main()
{
    RailwaySystem rs;

    int choice;
    int number;

    do
    {
        cout << "\nRailway Reservation System";
        cout << "\n1. Add Train";
        cout << "\n2. Display All Trains";
        cout << "\n3. Search Train";
        cout << "\n4. Train Count";
        cout << "\n5. Exit";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                rs.addTrain();
                break;

            case 2:
                rs.displayAllTrains();
                break;

            case 3:
                cout << "\nEnter Train Number: ";
                cin >> number;
                rs.searchTrainByNumber(number);
                break;

            case 4:
                cout << "\nTotal Train Objects: "
                     << Train::getTrainCount();
                break;

            case 5:
                cout << "\nProgram Ended.";
                break;

            default:
                cout << "\nInvalid Choice!";
        }

    } while(choice != 5);

    return 0;
}