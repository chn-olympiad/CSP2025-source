#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
ll n,m,c[500+10],sum=0,a[500+10];
string s;
bool vis[500+10];
void dfs(ll k,ll val){
	if(k==n+1){
		if(val>=m) sum++;
		return ;
	}
	for(ll i=1;i<=n;i++){
		if(vis[i]==false){
			vis[i]=true;
			if(k-val>c[i] || s[k-1]=='0') dfs(k+1,val);
			else dfs(k+1,val+1);
			vis[i]=false;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(ll i=1;i<=n;i++) cin>>c[i];
	ll f=0,ans=0;
	for(ll i=0;i<s.size();i++){
		if(s[i]=='0') f=1;
		else ans++;
	}
	if(ans<m){
		cout<<0;
		return 0;
	}
	if(f==0){
		ans=1;
		for(ll i=2;i<=n;i++){
			ans*=i;
			ans%=998244353;
		}
		cout<<ans;
		return 0;
	}
	dfs(1,0);
	cout<<sum;
	return 0;
}