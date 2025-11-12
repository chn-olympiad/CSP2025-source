#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+5;
const ll Mod=998244353;
ll n,m;
string s;
ll c[N],sum[N];
ll v[N];
bool vis[N];
ll ans=0;
void dfs(ll x){
	if(x==n+1){
		ll temp=0,sum=0;
		for(int i=0;i<n;i++){
			if(s[i]=='0') sum++;
			else{
				if(v[i+1]>sum){
					temp++;
				}
				else sum++;
			}
		}
		if(temp>=m){
			ans++;
			ans%=Mod;
		}
		return ; 
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue ;
		vis[i]=1;
		v[x]=c[i];
		dfs(x+1);
		vis[i]=0;
	}
	return ;
}
void solve(){
	cin >> n >> m >> s;
	ll cnt=0,cnt2=0;
	for(int i=1;i<=n;i++){
		cin >> c[i];
		if(c[i]!=0) cnt++; 
		if(s[i-1]!='0') cnt2++;
	}
	if(cnt2<m){
		cout << 0 << "\n";
		return ; 
	}
	if(m==n){
		if(cnt!=n||cnt2!=n) cout << 0 << "\n";
		else cout << sum[n] << "\n";
		return ;
	}
	else if(n<=10){
		dfs(1);
		cout << ans%Mod << "\n"; 
		return ;
	}
	else{
		cout << 0 << "\n";
	} 
	return ;
}
int main(){
	sum[1]=1;
	for(int i=2;i<=500;i++){
		sum[i]=sum[i-1]*i%Mod;
	}
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll T=1;
//	cin >> T;
	while(T--){
		solve();
	}
	return 0;
}

