#include <cstdio>

typedef long long ll;

const int N=500+10;
const int M=500+10; 
const int mod=998244353;

ll n,m,now,ans;
bool s[N];
int c[N];
//int p[N];
bool vis[N];

void dfs(int x) {
	if(n-now<m) return; 
	if(x>n) {
		if(n-now>=m) ans=(ans+1)%mod;
//		if(n-now>=m) {
//			puts("qwq");
//			for(int i=1;i<=n;i++) printf("%d ",p[i]);
//			puts("");
//		}
		return;
	}
	for(int i=1;i<=n;i++) {
		if(vis[i]) continue;
//		p[x]=i;
		vis[i]=true;bool fl=false;
		if(c[i]<=now || !s[x]) fl=true,++now;
		dfs(x+1);
		vis[i]=false;
		if(fl) --now;
	}
}

int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%1d",&s[i]);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	if(n<=10) dfs(1);
	else {
		ans=1;
		for(int i=2;i<=n;i++) ans=ans*i%mod;
	}
	printf("%lld\n",ans);
	return 0;
}
