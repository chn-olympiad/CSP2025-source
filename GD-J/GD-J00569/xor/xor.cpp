#include<bits/stdc++.h>

using namespace std;
long long n,m,a[500015],s,k,ma;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(long long i=1;i<=n;i++)
	{
		s=0,k=0;
		for(long long j=i;j<=n;j++)
		{
			s=s^a[j];
			if(s==m) k++,s=0;
		}
		if(ma<k) ma=k;
	}
	printf("%lld",ma);




	return 0;
 }
