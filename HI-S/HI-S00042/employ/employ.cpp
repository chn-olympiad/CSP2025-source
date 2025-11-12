#include<cstdio>
#include<iostream>
#include<cstring>
const int maxN=550,mod=998244353;
int n,m,c[maxN],num1,order[maxN];
long long ans;
char s[maxN];
bool vis[maxN];
bool check_order(){
	int failednum=0;
	for(int i=1;i<=n;i++)
		if(failednum>=c[order[i]]||s[i]=='0')
  		    failednum++;
	return n-failednum>=m?true:false;
}
void solve(int now){
	if(now==n+1){
		if(check_order()) ans++;
		ans%=mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=true;
		order[now]=i;
		solve(now+1);
		vis[i]=false;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",&s[0]+1);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	solve(1);
	printf("%lld",ans);
	return 0;
}
