#include <bits/stdc++.h>
using namespace std;
long long a[110];
long long n,m,t;

bool cmp(int x,int y)
{
	return x>y;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=0;i<n*m;i++)
		scanf("%lld",&a[i]);
	t=a[0];
	
	if(n==1&&m==1)
		printf("%lld %lld\n",m,n);
	else if(m==1)
	{
		sort(a,a+n*m,cmp);
		for(int i=0;i<n*m;i++)
		{
			if(a[i]==t)
				printf("%lld %d\n",m,i+1);
		}
	}

	return 0;
}
