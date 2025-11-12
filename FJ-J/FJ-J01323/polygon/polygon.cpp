//polygon
#include<bits/stdc++.h>
using namespace std;
int n;
const int MOD=998244353;
long long a,b;
long long C(int nu)
{
	b=b*nu;
	a=a*(n-nu+1);
	return a/b;
}
int main() 
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	long long ans=0;
	a=n*(n-1);
	b=2;
	for(int i=3;i<=n;i++)
	{
		ans+=(C(i))%MOD;
		ans=ans%MOD;
	}
	printf("%lld",ans);
	return 0;
}
