#include <bits/stdc++.h>
using namespace std;
long long s[105];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,rs;
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++)
	{
		cin>>s[i];
	}
	rs=s[1];
	sort(s+1,s+n*m+1,cmp);
	for(long long i=1;i<=n*m;i++)
	{
		if(s[i]==rs)
		{
			rs=i;
			break;
		}
	}
	long long c=(floor)((rs+m-1)/m),r;
	if(c%2==1)
	{
		rs-=(c-1)*m;
		r=rs%(m+1);
	}
	else
	{
		r=m-(rs%(m+1));
	}
	cout<<c<<' '<<r;
	return 0;
}
