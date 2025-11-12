#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
return x>y;
}
int main()
{
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m,a[11][11],b[101],c=0;
cin>>n>>m;
for(int i=1;i<=n;i++)
{
for(int j=1;j<=m;j++)
{
cin>>a[i][j];
b[++c]=a[i][j];
}
}
sort(b+1,b+1+c,cmp);
int pm,x,y,ans;
for(int i=1;i<=c;i++)
{
if(b[i]==a[1][1])
{
pm=i;
}
}
pm--;
y=pm/n+1;
pm++;
if(y%2==1)
{
    x=pm-(y-1)*n;
}
else
{
    x=n-(pm-(y-1)*n)+1;
}
cout<<y<<" "<<x;
return 0;
}
