#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int  a[101],n,m,t=1;
cin>>n>>m;
for(int i=1;i<=n*m;i++)
cin>>a[i];
for(int i=2;i<=m*n;i++)
{
	if(a[i]>a[1])
	t++;
}
if(t%m==0)
{
	cout<<t/m<<" ";
	if((t/m)%2==0)
	cout<<1;
	else
	cout<<n;
}
else
{
cout<<t/m+1<<" ";
if((t/m)%2==0)
cout<<t%m;
else
cout<<n-t%m+1;
}
return 0;
}
