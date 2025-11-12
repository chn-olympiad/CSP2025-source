#include <bits/stdc++.h>
using namespace std;
int fun(int n)
{
    int a[n+1][4],sat=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=3;j++)
        {
            cin>>a[i][j];
        }
    }
    int s[n+1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=3;j++)
        {
            for(int k=j;k<=3;k++)
            {
                if(a[i][k]>a[i][j])
                {
                    swap(a[i][k],a[i][j]);
                }
            }
        }
        s[i]=a[i][1];
    }
    for(int i=1;i<=n;i++)
    {
        sat+=s[i];
    }
    return sat;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n;
    cin>>t;
    int sat[6];
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        sat[i]=fun(n);
    }
    for(int i=1;i<=t;i++)
    {
        cout<<sat[i]<<endl;
    }
    return 0;
}
