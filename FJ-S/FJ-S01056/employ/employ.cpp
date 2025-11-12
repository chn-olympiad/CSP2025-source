#include<bits/stdc++.h>
using namespace std;
const int N=520,mod=998244353;
int n,m,h[N],c[N];
int s[N],vis[N];
long long ans,fac[N];
void dfs(int step){
	if(step==n+1){
		int sb=0;
		for(int i=1;i<=n;i++)
			if(!h[i]||sb>=c[s[i]])sb++;
		if(n-sb>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		s[step]=i;
		dfs(step+1);
		vis[i]=0;
	}
}
bool check(){
	fac[0]=1;
	for(int i=1;i<=500;i++)
		fac[i]=fac[i-1]*i%mod;
	int sb=0;
	for(int i=1;i<=n;i++)sb+=(c[i]==0);
	if(n-sb<m){
		ans=0;
		return 0;
	}
	if(m==1&&h[1]){
		ans=fac[n];
		return 0;
	}
	return 1;
}
int main(){
	ios::sync_with_stdio(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string str;cin>>str;
	for(int i=1;i<=n;i++)
		h[i]=str[i-1]-48;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	if(check())dfs(1);
	cout<<ans%mod;
	return 0;
}
