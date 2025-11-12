#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int x[t+1],y=0,a[t+1][t+1][t+1],b=0;
    for(int i=1;i<=t;i++) cin>>x[i];
    for(int i=1;i<=t;i++)
    {
        for(int j=i;j<=t-i;j++)
        {
            if(x[j]>x[j+1])
            {
                swap(x[j],x[j+1]);
            }
        }
    }
    for(int i=3;i<=t;i++)
    {
        for(int j=1;j<=i-1;j++)
        {
            y+=x[j];
        }
        y+=x[t];
        y=y/i;
        for(int j=1;j<=t;j++)
        {
            if(x[i]<t)
            {
                b++;
            }
        }
        b=b%998244353;
    }
    cout<<b;
    return 0;
}
