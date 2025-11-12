#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 98244353
#define N 505

int n,m,a[N],c[N];
string s;
int vis[N],ans;

void dfs(int p,int k){
	if(p==n+1){
		if(n-k>m) ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		if(a[i]||k>=c[i]){
			vis[p]=1;
			dfs(p+1,k+1);
			vis[p]=0;
		}else{
			vis[p]=1;
			dfs(p+1,k);
			vis[p]=0;
		}
	}
}

signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s; s=" "+s;
	for(int i=1;i<=n;i++){
		a[i]=s[i]-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1,0);
	cout<<ans<<"\n";
	return 0;
}

