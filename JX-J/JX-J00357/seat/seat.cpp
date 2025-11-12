#include<bits/stdc++.h>
using namespace std;
int n,m,a[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int b=0;
	for(int i=1;i<=n*m;i++)
	if(a[i]>=a[1]) b++;
	int c,r;
	if(b%n==0)
	{
		c=b/n;
		r=n;
	}
	else
	{
		c=b/n+1;
		if(c%2==0) r=n-b%n+1;
		else r=b%n;
	}
	cout<<c<<" "<<r;
	return 0;
}
