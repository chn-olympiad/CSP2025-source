#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=30;
const int mod=998244353;
int n,ans,a[N],dp[N];
bool vis[30][3000][100],f[30];
void dfs(int siz,int s,int mx){
	if(vis[siz][s][mx])return ;
	vis[siz][s][mx]=1;
	if(siz==0){
		if(s>2*mx)ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!f[i]){
			f[i]=1;
			mx=max(mx,a[i]);
			dfs(siz-1,(s+a[i])%mod,mx);
			f[i]=0;
		}
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	memset(f,0,sizeof(f));
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		dfs(i,0,0);
	}
	cout<<ans;
	return 0;
}
