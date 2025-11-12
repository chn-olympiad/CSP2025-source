#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 998244353;
ll n, i, e, m, flg, ans, b[55], p[55], c[55];
string s;
void dfs(ll k){
	if(k>n){
		ll luq=0;
		for(ll i=1;i<=n;i++)luq+=(s[i]=='1'&&luq>=i-c[p[i]]);
		ans+=(luq>=m);
		return;
	}
	for(ll i=1;i<=n;i++){
		if(!b[i]){
			p[k]=i, b[i]=1;
			dfs(k+1);
			b[i]=0;
		}
	}
}
ll QueAn(){
	cin>>n>>m>>s; s=' '+s;
	for(i=1;i<=n;i++)cin>>c[i], flg+=(c[i]>0)+(s[i]=='1');
	if(n==m){
		for(ans=i=1;i<=n;i++)ans=ans*i%MOD;
		return ans*(flg==n*2);
	} 
	dfs(1);
	return ans%MOD;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cout<<QueAn();
	return 0;
}

