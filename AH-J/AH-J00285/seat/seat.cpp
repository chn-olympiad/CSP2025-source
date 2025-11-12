#include <bits/stdc++.h>
using namespace std;
int n,m,c,r,a[105],k,t;
int main()
{
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n*m;i++)
cin>>a[i];
k=a[1];
sort(a+1,a+1+n*m);
for(int i=n*m;i>=1;i--)if(a[i]==k)t=i;
t=n*m+1-t;
if(t%n!=0)
{
	c=t/n+1;
	if(c%2==0)
	{
		r=n-t%n+1;
		}
		else r=t%n;
}
else 
{
	c=t/n;
	if(c%2==0)r=1;
	else r=n;
}
	cout<<c<<' '<<r;
return 0;
}
