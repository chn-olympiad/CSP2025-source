#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int h,s,da,ch;
int a[100][100];
int sdf(int n,int m,int k)
{
    ch=1;
    for(int i=0;i<n;i++)
    {
        ch+=n;
    }
    return ch;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>a[i][j];
        }

    }
    for(int i=n;i<n+m;i++)
    {
        for(int j=m;j<k;j++)
        {
            cin>>a[i][j];
        }
    }
       h=sdf(n,m,k)-n;
       cout<<h;
    return 0;
}

