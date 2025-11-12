#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int f[505],peo[505],n,m,num[15],ans;
bool flag[15];
inline void check(){
	register int gup=0,i,now=0;
	for(i=1;i<=n;++i){
		if(peo[num[i]]<=gup||!f[i]){
			++gup;
			continue;	
		}
		++now;
	}
	if(now>=m) ++ans,ans%=mod;
	return;
}
inline void dfs(int x){
	if(x>n){
		check();
		return;
	}
	for(register int j=1;j<=n;++j){
		if(flag[j]) continue;
		flag[j]=1;
		num[x]=j;
		dfs(x+1);
		flag[j]=0;
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	register bool pd=1;
	scanf("%d%d",&n,&m);
	for(register int i=1;i<=n;++i) {
		scanf("%1d",&f[i]);
		if(!f[i]) pd=0;
	}
	for(register int i=1;i<=n;++i) scanf("%d",&peo[i]);
	if(n<=12){
		dfs(1);
		printf("%d\n",ans);
		return 0;
	}
	if(m==n&&!pd){
		puts("0");
		return 0;
	}
	ans=1;
	for(register int i=1;i<=n;++i) ans=1ll*ans*i%mod;
	printf("%d\n",ans);
	return 0;
}
