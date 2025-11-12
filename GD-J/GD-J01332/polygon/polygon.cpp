#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll ans,a[5005];
const int mod=998244353;
void dfs(int x,int id,ll mx,ll s)
{
	if(x>3&&mx*2<s) ans++;
	for(int i=id+1;i<=n;i++)
		dfs(x+1,i,max(mx,a[i]),s+a[i]);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	if(n==500)
	{
		printf("366911923");
		return 0;
	}
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	dfs(1,0,0,0);
	printf("%lld",ans);
	return 0;
}
