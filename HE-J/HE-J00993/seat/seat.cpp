#include <bits/stdc++.h>
using namespace std;
int c,r,a[103][103],n=0,sum=0;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>c>>r;
    for (int i=0;i<c;i++)
    {
        for (int j=0;j<r;j++)
        {
            cin>>a[i][j];

        }
    }
    for (int i=0;i<c;i++)
    {
        for (int j=0;j<r;j++)
        {

            if (a[i][j]>a[1][1])
            {
                sum++;

            }
        }
    }
    for (int i=0;i<c;i++)
    {
        if (i%2==0)
        {
            for (int j=r-1;j>0;j--)
            {
                n++;
                if (n==sum)
                {
                    cout<<j+1<<" "<<i+1;
                }
            }
        }
        else if (i%2!=0)
        {
            for (int j=0;j<r;j++)
            {
                n++;
                if (n==sum)
                {
                    cout<<j+1<<" "<<i+1;
                }
            }
        }

    }
}
