#include<bits/stdc++.h>
using namespace std;
int n,m,a[1500],b;
bool tmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=m*n;i++)
    {
        cin>>a[i];
    }
    b=a[1];
    sort (a+1,a+m*n+1,tmp);
    for (int i=1;i<=m;i++)
    {
        int pos=0;
        if (i%2==1)
        {
            for (int j=1+(i-1)*n;j<=i*n;j++)
            {
                pos++;
                if (a[j]==b)
                {
                    cout<<i<<" "<<pos;
                    return 0;
                }
            }
        }
        else
        {
            for (int j=i*n;j>=1+(i-1)*n;j--)
            {
                pos++;
                if (a[j]==b)
                {
                    cout<<i<<" "<<pos;
                    return 0;
                }
            }
        }
    }
    return 0;
}
