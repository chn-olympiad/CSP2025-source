#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998244353;
ll n,m,c[550],B,cnt,a[550],ans;
ll jc[550],dp[550];
string s;
bool A=1,vis[550];
void dfs(int d){
	if(d==n+1){
		int tmp=0;
		for(int i=1;i<=n;i++) if(c[a[i]]<=tmp||s[i-1]=='0') tmp++;
		if(n-tmp>=m) ans++;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		a[d]=i;
		vis[i]=1;
		dfs(d+1);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	jc[0]=1;
	for(int i=1;i<=n;i++) jc[i]=jc[i-1]*i%mod;
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++) if(s[i]=='0') A=0,B++;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0) cnt++;
	}
	if(A){
		if(m==n){
			if(cnt) cout<<0;
			else cout<<jc[n]%mod;
			return 0;
		}
		dfs(1);
	}
	if(m==1){
		cout<<jc[n]%mod;
		return 0;
	}
	if(m==n){
		cout<<0;
		return 0;
	}
	if(n-B<m){
		cout<<0;
		return 0;
	}
	dfs(1);
	cout<<ans%mod;
	return 0;
}
