#include<bits/stdc++.h>
using namespace std;
long long m,n,x[114514];
bool cmp(long long a,long long b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++)
	{
		cin>>x[i];
	}
	long long p=x[1];
	sort(x+1,x+n*m+1,cmp);
	long long k=0;
	for(long long i=1;i<=n*m;i++)
	{
		if(x[i]==p)
		{
			k=i;
			break;
		}
	}
	cout<<(k+n-1)/n<<" ";
	if(((k+n-1)/n)%2==1)
	{
		if(k%n==0)
		cout<<n;
		else
		cout<<k%n; 
	}
	if(((k+n-1)/n)%2==0)
	{
		if(k%n==0)
		cout<<1;
		else
		{
			cout<<n-(k%n)+1;
		}
	}
	return 0;
}
