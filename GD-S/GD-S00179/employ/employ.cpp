#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
string s;
const int mod=998244353;
int c[600];
int dp[600][600];
bool vis[600];
int ans=0;
int jc[600];
void dfs(const int &x,const int &zf,const int &an){
	if(x>n){
		if(an>=m){
			ans++;
			ans%=mod;
		}
		return;
	}
	if(n-x+1+an<m)return;
	if(an>=m){
		ans+=jc[n-x+1];
		ans%=mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			if(s[x]=='1'&&zf<c[i])dfs(x+1,zf,an+1);
			else dfs(x+1,zf+1,an);
			vis[i]=0;
		}
	}
	return;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	jc[0]=1;
	for(int i=1;i<=n;i++){
		jc[i]=jc[i-1]*i;
		jc[i]%=mod;
	}
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1,0,0);
	cout<<ans%mod;
	return 0;
}
