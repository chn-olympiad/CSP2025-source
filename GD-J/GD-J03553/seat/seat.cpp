#include<bits/stdc++.h>
using namespace std;
long long a[1000010];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	scanf("%lld%lld",&n,&m);
	scanf("%lld",&a[1]); 
	long long k=a[1];
	for(long long i=2;i<=n*m;i++)
	{
		scanf("%lld",&a[i]);
	}
	long long id=1,t=1;
	sort(a+1,a+n*m+1);
	for(long long i=n*m;i>=1;i--)
	{
		if(a[i]==k)
		{
			break;
		}
		id++;
	}
	id--;
	long long x=1,y;
	for(long long i=1;i<=m;i++)
	{
		if(id>=n)
		{
			id-=n;
			x++;
		}
		else
		{
			break;
		}
		t^=1;
	}
	if(t)
	{
		y=id+1;
	}
	else
	{
		y=n-id;
	}
	printf("%lld %lld",x,y);
	return 0;
}

