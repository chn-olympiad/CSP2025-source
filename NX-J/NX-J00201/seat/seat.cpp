#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
bool vmp(int a,int b)
{
    return a>b;

}
int a[10000000];
int s[1000][1000];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n;
    int m;
    cin>>n>>m;
    cin>>a[1];
    int sum=a[1];
    for(int i=2;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int sb=0;
    sort(a+1,a+1+n*m,vmp);
    for(int p=1;p<=n;p++)
    {

        if(p%2==1)
        {
            for(int t=1;t<=m;t++)
            {
                sb+=1;
                s[p][t]=a[sb];
            }
        }
        else
        {
            for(int t=m;t>=1;t--)
            {
                sb+=1;
                s[p][t]=a[sb];
            }
        }
    }
    for(int u=1;u<=n;u++)
    {

        for(int y=1;y<=m;y++)
        {
            if(s[u][y]==sum)
            {
                cout<<u<<" "<<y;
                return 0;
            }
        }

    }

}
