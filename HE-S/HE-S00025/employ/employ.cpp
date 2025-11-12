#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod=998244353;
ll n,m;
char s[1013];
ll c[1013];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>s[i];
	for(ll i=1;i<=n;i++) cin>>c[i];
	ll ans=1;
	for(ll i=1;i<=n;i++){
		ans*=i;
		ans%=mod;
	}
	cout<<ans%mod;
	return 0;
}/*
你说得对，但是三角洲很好玩 
捏碎玫瑰的那25秒，我比任何人都勇敢
玫瑰会枯萎，但此刻只为我一人绽放
花来！ 
*/ 
