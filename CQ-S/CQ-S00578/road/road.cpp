#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,m,k,a,b,ans;
ll c[1000005];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&a,&b,&c[i]);
	}
	sort(c+1,c+m+1);
	for(int i=1;i<n;i++)
	{
		ans+=c[i];
	}
	printf("%lld",ans);
	return 0;
}
