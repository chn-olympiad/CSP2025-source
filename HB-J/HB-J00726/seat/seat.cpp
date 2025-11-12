#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s[n*m+1];
	int r;
	cin>>r;
	s[1]=r;
	for(int i=2;i<=n*m;i++)
	{
		cin>>s[i];
	}
	sort(s+1,s+n*m+1);
	for(int i=1;i<=n*m;i++)
	{	if(s[i]==r)
		{
			r=i;
			break;
		}
	}
	if(r%n==0)
	{
		int g=r/n;
		if(g%2==0)
		{
			cout<<m-g+1<<" "<<1;
			return 0;
		}
		if(g%2!=0)
		{
			cout<<m-g+1<<" "<<n;
			return 0;
		}
	}
	if(r%n!=0)
	{
		int g=r/n;
		if(g%2==0)
		{
			cout<<m-g<<" "<<n-r%n+1;
			return 0;
		}
		if(g%2!=0)
		{
			cout<<m-g<<" "<<r%n;
			return 0;
		}
	}
	return 0;
}
