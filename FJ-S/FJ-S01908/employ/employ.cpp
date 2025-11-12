#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=1e4+5;
const ll maxx=1e6+5;
const ll mod=998244353;
ll n,m,c[505],ans,day[505],sum[505],aa,bb;
bool book[505];
string s;
void dfs(ll k,ll li,ll liu){
	if(k>n){
		if(liu>=m) ans=(ans+1)%mod;
		return;
	}
	if(liu+(sum[n]-sum[k-1])<m) return;
	if(liu>=m){
		ll cnt=1;
		for(int i=1;i<=n-k+1;i++) cnt=(cnt*i)%mod; 
		ans=(ans+cnt)%mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(book[i]) continue;
		book[i]=1;
		aa=li,bb=liu;
		if(day[k]==0) aa++;
		else{
			if(li>=c[i]) aa++;
			else bb++;
		}
		dfs(k+1,aa,bb);
		book[i]=0;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++){
		day[i]=s[i-1]-'0';
		sum[i]=sum[i-1]+day[i];
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
