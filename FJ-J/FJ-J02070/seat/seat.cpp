#include<bits/stdc++.h>
using namespace std;
int a[101];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
int n,m,i,h,l,s;
cin>>n>>m;
for(i=1;i<=n*m;i++)
{
	cin>>a[i];
}s=a[1];
sort(a+1,a+n*m+1);
for(i=1;i<=m*n;i++)
{
	if(s==a[i])
	{
		s=i;
		break;
	}
}
s=n*m-s+1;
l=(s+n-1)/n;
s=s-(l-1)*n;
if(l%2==1)
{
	h=s;
}
else
h=m-s+1;
cout<<l<<" "<<h;
}
