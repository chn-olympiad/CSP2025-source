#include<bits/stdc++.h>
#define MAXN 520
using namespace std;
namespace Aleister{
	const int mod=998244353;
	int n,m,c[MAXN],p[MAXN];
	char s[MAXN];
	int ans,jc[MAXN];
	bool cho[MAXN];
	void dfs(int u,int cc){
		if(u-1-cc>=m) return ans+=jc[n+1-u],void();
		else if(u-1-cc+(n-u+1)<m) return;
//		for(int i=1;i<=n;i++) cerr<<p[i]<<' ';
//		cerr<<'\n';
//		cerr<<cc<<'\n';
		if(u>n) return;
		for(int i=1;i<=n;i++){
			if(cho[i]) continue;
			cho[i]=1,p[u]=i;
			if(cc>=c[i]) dfs(u+1,cc+1);
			else{
				if(s[u]=='0') dfs(u+1,cc+1);
				else dfs(u+1,cc);
			}
			cho[i]=0,p[u]=0;
		}
	}
	int main(){
		freopen("employ.in","r",stdin);
		freopen("employ.out","w",stdout);
		scanf("%d%d%s",&n,&m,s+1),jc[0]=1;
		for(int i=1;i<=n;i++) scanf("%d",&c[i]),jc[i]=1ll*jc[i-1]*i%mod;
		dfs(1,0),printf("%d\n",ans);
		return 0;
	}
}
int main(){
	return Aleister::main();
}
//º¢×ÓÃÇ£¬ÍËÒÛÌ«Ë¬ÁË 
