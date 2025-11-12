#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],pw=0;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n*m;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]>a[1])
		{
			pw++;
		}
	}
	if(pw%(n<<1)<n)
	{
		printf("%lld %lld",pw/n+1,pw%(n<<1)+1);
	}
	else
	{
		printf("%lld %lld",pw/n+1,(n<<1)-pw%(n<<1));
	}
}
