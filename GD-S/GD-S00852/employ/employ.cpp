#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,bz[505],c[505],p[505],ans;
string s;
void check(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(cnt>=c[p[i]]) cnt++;
		else{
			if(s[i]=='0') cnt++;
		}
	}
	if(n-cnt>=m) ans++;
}
void dfs(int u){
	if(u>n){
		check();
		return;
	}
	for(int i=1;i<=n;i++){
		if(!bz[i]){
			p[u]=i,bz[i]=1;
			dfs(u+1);
			bz[i]=0;
		}
	}
}
void work1(){
	for(int i=1;i<=n;i++) if(s[i]=='0') return;
	for(int i=1;i<=n;i++) if(c[i]==0) return;
	ans=1;
	for(int i=1;i<=n;i++) ans=1ll*ans*i%mod;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	if(m==n){
		work1();
		printf("%d\n",ans);
		return 0;
	}
	dfs(1);
	printf("%d\n",ans);
	return 0;
}
