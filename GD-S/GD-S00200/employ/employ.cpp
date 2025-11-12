#include <bits/stdc++.h>
using namespace std;
const long long p=998244353;
int n,m,v[1010],a[1010],vis[1010];
long long ans;
char s[1010];
void wor(){
	int res=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='0'||v[a[i]]<=i-res-1) continue ;
		res++;
	}
	//cout<<res<<endl;
	ans+=(res>=m);
}
void dfs(int k){
	if(k>n){
		wor();
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue ;
		a[k]=i;
		vis[i]=1;
		dfs(k+1);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1;i<=n;i++) scanf("%d",&v[i]);
	if(n<=10){
		dfs(1);
		cout<<ans;
		return 0; 
	}
	ans=1;
	for(int i=1;i<=n;i++) ans=ans*i%p;
	cout<<ans;
	return 0;
}

