#include<bits/stdc++.h>
using namespace std;

int n,m,c,r;
int a[105];

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int u=a[1];
	sort(a+1,a+n*m+1);
	int pos;
	for(int i=1;i<=n*m;i++)
		if(a[i]==u)
		{
			pos=n*m-i+1;
			break;
		}
	if(pos%n==0)
	{
		c=pos/n;
		if(c%2==1)
			cout<<c<<' '<<n;
		else
			cout<<c<<' '<<1;
		return 0;
	}
	c=pos/n+1;
	r=pos%n;
	if(c%2==0)
		r=n-r+1;
	cout<<c<<' '<<r;
	return 0;
}