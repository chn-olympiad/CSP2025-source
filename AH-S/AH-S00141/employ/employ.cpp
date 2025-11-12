#include<bits/stdc++.h>
using namespace std;
string s;
int n,m,a[505],vis[505];
long long ans,yu[505];
void dfs(int now,int hav,int brok){
	if(now==n+1){
		if(hav>=m)ans++;
		ans%=998244353;
		return;
	}
	if(n-now+1+hav<m)return;
	if(hav>=m){
		ans=(ans+yu[n-now+1])%998244353;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		if(brok<a[i]&&s[now-1]=='1')dfs(now+1,hav+1,brok);
		else dfs(now+1,hav,brok+1);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	yu[1]=1;
	for(int i=2;i<=n;i++)yu[i]=yu[i-1]*i%998244353;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
