#include<bits/stdc++.h>
using namespace std;
int m,n,i,j,a[101],r,maxn,maxnn,s,b[101][101];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(i=1;i<=n*m;i++)
     cin>>a[i];
    r=a[1];
    for(i=1;i<n*m;i++)
    {
        maxn=a[i+1];
        for(j=i+1;j<=m;j++)
            if(a[j]>maxn)maxn=a[j];maxnn=j;
        if(a[i]<a[maxnn])swap(a[i],a[maxnn])
    }
    for(j=1;j<=m;j++)
    {
        if(j%2==1)
         for(i=1;i<=n;i++)
        {
            sum++;
            b[i][j]=a[sum];
        }
        else
         for(i=n;i>=1;i--)
        {
            sum++;
            b[i][j]=a[sum];
        }
    }
    for(i=1;i<=n;i++)
     for(j=1;j<=m;j++)
     {
         if(b[i][j]==r)cout<<j<<' '<<i;
         break;
     }
     return 0;
}
