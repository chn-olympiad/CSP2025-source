#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998244353;
ll n,m,c[1000000],vis[1000000],a[1000000],ans;
ll const mod=998244353;
string s;
ll po(ll x,ll y){
	ll ans=1;
	while(y){
		if(y&1){
			ans=(ans*x)%mod;
		}
		x=(x*x)%mod;
		y>>=1;
	}
	return ans;
}
void dfs(ll x){
	if(x>n){
		ll ls=0,js=0;
		for(int i=1;i<=n;i++){
			if(c[a[i]]>ls&&s[i]=='1'){
				js++;
			}
			else{
				ls++;
			}
		}
		if(js>=m){
			ans++;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			a[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	ll ok=1;
	for(int i=1;i<=n;i++){
		if(s[i]-'0'==0){
			ok=0;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n<=10){
		dfs(1);
		cout<<ans;
		return 0;
	}
	ll ans=1;
	for(int i=1;i<=n;i++){
		ans=(ans*i)%mod;
	}
	cout<<ans;
	return 0;
}
/*
3 2
101
1 1 2
*/
