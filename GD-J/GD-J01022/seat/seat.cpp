#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	scanf("%lld",&n);
	scanf("%lld",&m);
	long long nm=n*m,mn;
	vector<long long> a(nm);
	for(long long i=0;i<nm;i++)
		scanf("%lld",&a[i]);
	mn=a[0];
	sort(a.begin(),a.end());
	long long x=1,y=1;
	for(long long i=nm-1;i>=0;i--)
	{
		if(y==n+1)
		{
			y=n;
			x++;
		}
		else if(y==0)
		{
			y=1;
			x++;
		}
		if(a[i]==mn)
		{
			printf("%lld %lld",x,y);
			return 0;
		}
		if(x%2==1)
			y++;
		else
			y--;
	}
	return 0;
}
