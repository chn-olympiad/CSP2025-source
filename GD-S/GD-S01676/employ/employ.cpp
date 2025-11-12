#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 505
int n,m;
int pat[N],used[N];
char dif[N];
ll ans,mo=998244353;
ll pre[N];
void dfs(int x,int giv){
	if(m+giv>n) return;
	if(x-giv-1>=m){
		ans=(ans+pre[n-x+1])%mo;
		return;
	}
	if(x>n) return;
	for(int i=1;i<=n;i++){
		if(used[i]) continue;
		used[i]=1;
		if(giv>=pat[i]||dif[x]=='0') dfs(x+1,giv+1);
		else dfs(x+1,giv);
		used[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",dif+1);
	for(int i=1;i<=n;i++) scanf("%d",&pat[i]);
	pre[0]=1;
	for(int i=1;i<=n;i++) pre[i]=(pre[i-1]*i)%mo;
	dfs(1,0);
	printf("%lld",ans);
	return 0;
}

