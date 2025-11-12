#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=998244353;
int n,m,ans=0;
int c[505],f[505];
char x[505];
void dfs(int dep,int s,int w){
	if(n-w<m)return;
	if(dep>n){
		if(s>=m){
			ans++;
			ans%=mod;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(f[i])continue;
		f[i]=1;
		int ts=s,tw=w;
		if(c[i]<=w)w++;
		else if(x[dep]=='1')s++;
		else w++;
		dfs(dep+1,s,w);
		s=ts;
		w=tw;
		f[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	if(m==n){
		int cf=1;
		for(int i=1;i<=n;i++){
			cf*=i;
			cf%=mod;
		}
		cout<<cf;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1,0,0);
	cout<<ans;
    return 0;
}
