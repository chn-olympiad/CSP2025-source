#include<bits/stdc++.h>
using namespace std;
const int mx1=110,mx2=15;
int a[mx1],b[mx2][mx2],n,m,i,j,r,c,x;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(i=1;i<=m*n;i++)cin>>a[i];x=a[1];
    for(i=1;i<=m*n;i++)
    for(j=1;j<=m*n;j++)
    if(a[j]<=a[i])swap(a[i],a[j]);i=1;
    for(r=1;r<=n;r++)
    if(r%2==0){
        for(c=m;c>=1;c--)b[r][c]=a[i++];
    }
    else{
        for(c=1;c<=m;c++)b[r][c]=a[i++];
    }
    for(r=1;r<=n;r++)
    if(r%2==0){
        for(c=m;c>=1;c--)if(b[r][c]==x)cout<<r<<' '<<c;
    }
    else{
        for(c=1;c<=m;c++)if(b[r][c]==x)cout<<r<<' '<<c;
    }
    return 0;
}
