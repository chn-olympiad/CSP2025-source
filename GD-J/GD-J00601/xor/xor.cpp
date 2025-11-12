#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define mod 1000000007
#define ari(x) array<int,(x)>
#define lcm(x,y) x/__gcd(x,y)*y
#define lowbit(x) ((x) & -(x))

const int N = 5e5+5,M = (1<<22)+5;
int f[N],p[M],g[N],a[N],n,k,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i = 1;i <= n;i++) cin>>a[i],a[i]^=a[i-1];
	memset(p,-1,sizeof(p));
	p[0] = 0;
	for(int i = 1;i <= n;i++){
		if(p[a[i]^k] != -1) f[i] = g[p[a[i]^k]] + 1;
		g[i] = max(g[i-1],f[i]);
		ans = max(ans,f[i]);
		p[a[i]] = i;
	}
	cout<<ans;
	return 0;
}
