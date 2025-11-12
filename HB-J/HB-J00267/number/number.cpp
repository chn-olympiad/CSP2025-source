#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char number[100000] = {};
    for (long long l = 0;l<100000;l++)
    {
        cin>>number[l];
        if((number[l] != '1') and (number[l] != '2') and (number[l] != '3') and (number[l] != '4') and (number[l] != '5') and (number[l] != '6') and (number[l] != '7') and (number[l] != '8') and (number[l] != '9') and (number[l] != '0') or (number[l] == '@'))
        {
            break;
        }
    }
    long long turns = sizeof(number);
    long long s = 0;
    for(long long i = 0;i<turns;i++)
    {
        for(long long j = 0;j<turns-1;j++)
        {
            if (number[j]<number[j+1])
            {
                s = number[j];
                number[j] = number[j+1];
                number[j+1] = s;
            }
        }
    }
    for (long long k = 0;k<turns;k++)
    {
        cout<<number[k];
    }
    return 0;
}
