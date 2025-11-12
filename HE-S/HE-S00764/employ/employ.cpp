#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+5;
const int mod=998244353;
string s;
ll n,m,c[N],f[N],ans,cnt,num;
ll power(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res%mod;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	f[0]=f[1]=1;
	for(ll i=1;i<=n;i++){
		cin>>c[i];
		if(cnt>=c[i]) cnt++;
	}
	for(ll i=2;i<=n;i++){
		f[i]=f[i-1]*i%mod;
	}
	ans=f[n]%mod;
	if(n-cnt+1<m) cout<<0;
	else cout<<ans%mod;
	return 0;
}
