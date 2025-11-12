#include<iostream>
#include<cmath>
using namespace std;
int n,m,asd=0,x=0;
int a[10010],b[10010];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==0)
        {
            x++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    for(int j=1;j<=n;j++)
    {
        if(a[j]==0&&b[j]>=j)
        {
            asd++;
        }
    }
    if(asd==2)
    {
        cout<<asd;
    }
    else
    {
        asd=0;
        for(int j=1;j<=x*(x+1)/2;j++)
    {
        for(int i=j;i<=n;i++)
    {
        if(a[i]==0&&b[i]>=i)
        {
            asd++;
        }
    }
    }
    cout<<asd;
    }
    return 0;
}
