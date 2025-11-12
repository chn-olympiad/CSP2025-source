#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,mod=998244353,INF=INT_MAX;
int n,m,c[N],vis[N],t[N],p[N],ans,all;
char s[N];
void dfs(int k){
	if(k>n){
		if(all){
			ans=(ans+1)%mod;
			return;
		}
		int cnt=0;
		memset(t,0,sizeof t);
		for(int i=1;i<=n;i++){
			if(s[i]=='0'){
				t[p[i+1]]++;
				continue;
			}
			t[p[i]]+=t[p[i-1]];
			if(c[p[i]]>t[p[i]])cnt++;
			else t[p[i+1]]++;
		}
		if(cnt>=m)ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		p[k]=i;//记录第k天是谁 
		dfs(k+1);
		vis[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		if(s[i]!=1)all=0;
	}
	dfs(1);
	printf("%d",ans%mod);
}
