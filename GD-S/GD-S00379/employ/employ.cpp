#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e3+10,MOD=998244353;
int n,m,c[MAXN],a[MAXN],vis[MAXN],zb,num,sum,t[MAXN],f[MAXN][MAXN];
long long ans,fac[MAXN];
char s[MAXN];
void dfs(int x){
	if(x>n){
		if(zb>=m) ++ans;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		a[x]=i,vis[i]=1;
		int g=0;
		if(num>=c[i]||s[x]=='0') ++num,g=1;
		else zb++;
		if(zb<m) dfs(x+1);
		else ans=(ans+fac[n-x])%MOD;
		vis[i]=0;
		if(g) num--;
		else zb--;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,s+1),fac[0]=1;
	for(int i=1;i<=n;i++) scanf("%d",&c[i]),sum+=(s[i]=='1');
	if(m>sum){
		putchar('0');
		return 0;
	}
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%MOD;
	if(m==n){
		if(sum!=n){
			putchar('0');
			return 0;
		}
		for(int i=1;i<=n;i++){
			if(!c[i]){
				putchar('0');
				return 0;
			}
		}
		printf("%lld",fac[n]);
		return 0;
	}
	dfs(1),printf("%lld",ans);
	return 0;
}
