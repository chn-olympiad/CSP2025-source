#include<bits/stdc++.h>
using namespace std;

const int mod=998244353;
int n,m,ans;
string H;
int c[1000];
int p[1000],vis[1000];

void init(){
	cin>>n>>m>>H;
	for(int i=1;i<=n;i++)cin>>c[i];
}

bool ok(){
	int g=0;
	for(int i=0;i<n;i++){
		if(c[p[i]]<=g||H[i]=='0')g++;
	}
	if(n-g>=m)return 1;
	return 0;
}

void dfs(int k){
	int sum=0;
	if(k==n){
		if(ok())ans++;
		ans%=mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		p[k]=i;vis[i]=1;
		dfs(k+1);
		p[k]=0;vis[i]=0;
	}
	return;
}

void solve(){
	init();
	dfs(0);
	cout<<ans<<"\n";
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	solve();
	return 0;
}

