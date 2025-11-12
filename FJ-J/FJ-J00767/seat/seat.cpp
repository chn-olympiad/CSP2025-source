#include <bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long  n,m;
	cin>>n>>m;
	long long g[n*m];
	for(long long i=0;i<n*m;i++)
	{
		cin>>g[i];
	}
	long long r=g[0],x;
	sort(g,g+n*m,cmp);
	for(long long i=0;i<n*m;i++)
	{
		if(g[i]==r)
		{
			x=i+1;
		}
	}
	if(x%n==0)
	{
		cout<<x/n<<" ";
		if((x/n)%2==0)
		{
			cout<<1;
		}
		else
		cout<<n;
	}
	else
	{
		cout<<x/n+1<<" ";
		if((x/n+1)%2==1)
		{
			cout<<x%n;
		}
		else
		{
			cout<<n-(x%n)+1;
		}
	}
	return 0;
}
