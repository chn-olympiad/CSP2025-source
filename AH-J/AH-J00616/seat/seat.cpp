#include<bits/stdc++.h>
using namespace std;
long long a[15][15],s[105];
bool cmp(long long x,long long y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,i,x,y,t;
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
	{
		cin>>s[i];
	}
	t=s[1];
	sort(s+1,s+n*m+1,cmp);
	for(i=1;i<=n*m;i++)
	{
		if(s[i]==t)
		{
			t=i;
			break;
		}
	}
	x=ceil(t*1.0/n);
	y=t%n;
	if(x%2==0)
	{
		if(y==0)
		{
			cout<<x<<" "<<1;
			return 0;
		}
		cout<<x<<" "<<n-y+1;
	}
	else
	{
		if(y==0)
		{
			cout<<x<<" "<<n;
			return 0;
		}
		cout<<x<<" "<<y;
	}
	return 0;
}
