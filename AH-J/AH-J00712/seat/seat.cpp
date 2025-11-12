#include<bits/stdc++.h>
using namespace std;
const int N=400;
struct s
{
	long long cj,xr;
}a[N];
bool cmp(s x,s y)
{
	return x.cj>y.cj;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++)
	{
		cin>>a[i].cj;
		if(i==1)
		{
			a[i].xr=1;
		}
	}
	sort(a+1,a+n*m+1,cmp);
	for(long long i=1;i<=n*m;i++)
	{
		if(a[i].xr==1)
		{
			if(i%m==0)
			{
				if((i/m)%2==0)
				{
					cout<<i/m<<" "<<1;
				}
				else
				{
					cout<<i/m<<" "<<n;
				}
				return 0;
			}
			else
			{
				if((i/m+1)%2==0)
				{
					cout<<i/m+1<<" "<<n-(i%m)+1;
				}
				else
				{
					cout<<i/m+1<<" "<<i%m;
				}
			}
			return 0;
		}
	}
	return 0;
}
