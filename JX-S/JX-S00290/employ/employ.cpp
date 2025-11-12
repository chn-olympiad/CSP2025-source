#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
ll n,c[509],m;
string s;
ll res=0,num[509],vis[509];
void dfs(ll step){
	if(step>n){
		ll out=0,right=0;
		for(ll i=1;i<=n;++i){
			if(s[i-1]=='0'){
				++out;
			}else {
				if(out>=c[num[i]])++out;
				else ++right;
			}
		}
		if(right>=m)res=(res+1)%mod;
	}
	for(ll i=1;i<=n;++i){
		if(!vis[i]){
			vis[i]=1;
			num[step]=i;
			dfs(step+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	cin>>s;
	ll cnt1=0;
	for(ll i=1;i<=n;++i){
		cin>>c[i];
		if(s[i-1]=='1')++cnt1;
	}
	if(cnt1==n){
		ll ans=1;
		for(ll i=1;i<=n;++i){
			ans=ans*i;
			ans%=mod;
		}
		cout<<ans<<'\n';
		return 0;
	}
	if(cnt1<m){
		cout<<0<<'\n';
		return 0;
	}
	dfs(1);
	cout<<res<<'\n';
	return 0;
}










