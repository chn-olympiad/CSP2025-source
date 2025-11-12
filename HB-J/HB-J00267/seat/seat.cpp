#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    //cout<<n<<m<<endl;
    int numbers = n*m,save = 0;
    int marks[numbers] = {};
    for (int i = 0;i<numbers;i++)
    {
        cin>>marks[i];
    }
    int little_a_mark = marks[0];
    for (int j = 0;j<numbers;j++)
    {
        for(int k = 0;k<numbers-1;k++)
        {
            if(marks[k]<marks[k+1])
            {
                save = marks[k];
                marks[k] = marks[k+1];
                marks[k+1] = save;
            }
        }
    }
    /*for (int o = 0;o<numbers;o++)
    {
        cout<<marks[o]<<endl;
    }*/
    int a_seat;
    for(int l = 0;l<numbers;l++)
    {
        if(marks[l] == little_a_mark)
        {
            a_seat = l+1;
            break;
        }
    }
    cout<<a_seat<<endl;
    int c,y;
    c = a_seat / (n) + 1;
    if (c%2 == 0)
    {
        y = n - (a_seat % n);
        //cout<<y<<endl;
        if(y == 0)
        {
            y = 1;
        }
        else
        {
            y+=1;
        }
    }
    else
    {
        y = a_seat % n;
        //cout<<y<<endl;
        if (y == 0)
        {
            y = n;
        }
    }
    cout<<c<<' '<<y<<endl;
    return 0;
}
