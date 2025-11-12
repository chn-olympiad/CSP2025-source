#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mod 998244353

int n,m;
ll ans;

int s[510],c[510];
int p[510];

bool vis[510];

void dfs(int x,int len){
	if(x>len){
		ll res=0;
		for(int i=1;i<=len;++i){
			if(i-res-1>=c[p[i]]) continue;
			if(s[i]==1) ++res;
		}
		if(res>=m) ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=len;++i){
		if(vis[i]) continue;
		p[x]=i;
		vis[i]=1;
		dfs(x+1,len);
		p[x]=0;
		vis[i]=0;
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%1d",&s[i]);
	for(int i=1;i<=n;++i) scanf("%d",&c[i]);
	dfs(1,n);
	printf("%lld\n",ans);
	fclose(stdin);fclose(stdout);
	return 0;
} 
