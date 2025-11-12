#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int mian()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a[11][11]={0};
    int n,m,R,h;
    bool cmp(int x,int y)
    {
        return(x>y);
    }
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
     {
          cin>>a[i];
     }
    R=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
    {
          if(a[i]==R) {h=i;break;}
    }
    for(int i=1;i<=h;i++)
    {
       for(int j=1;j<=m;j++)
    }
    return 0;
}
