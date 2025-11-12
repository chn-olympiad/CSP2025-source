#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
long long n,m,a[1000][1000],l=1,h=1;
cin>>n>>m;
for(int i=1;i<=n;i++)
{
for(int j=1;j<=m;j++)
{
cin>>a[i][j];
}
}
for(int i=1;i<=n;i++)
{
for(int j=1;j<=m;j++)
{
if(a[1][1]<a[i][j]&&l%2==1)
{
h++;
}
else if(a[1][1]<a[i][j]&&l%2==0)
{
h--;
}
if(h>n)
{
h=n;
l++;
}
if(h<1)
{
h=1;
l++;
}
}
}
cout<<l<<" "<<h;
return 0;
}
