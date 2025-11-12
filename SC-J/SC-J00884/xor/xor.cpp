#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
int n;
ll s[N],a[N],f[N],ans=0,k;
map<ll,ll> g;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++) s[i]=(s[i-1]^a[i]);
	g[0]=0;
	for(int i=1;i<=n;i++)
	{
		if(g.find(s[i]^k)==g.end()) f[i]=0;
		else f[i]=g[s[i]^k]+1;
		f[i]=max(f[i-1],f[i]);
		g[s[i]]=max(g[s[i]],f[i]);
		ans=max(ans,f[i]);
	}
	printf("%lld",ans);
	return 0;
}