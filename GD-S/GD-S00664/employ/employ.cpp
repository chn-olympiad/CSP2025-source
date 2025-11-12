#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN=500,mod=998244353;
ll n,m,c[MAXN+5],p[MAXN+5];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	ll tot=0;
	for(ll i=0;i<n;i++) if(s[i]=='1') tot++;
	if(tot<m){
		cout<<"0\n";
		return 0;
	}
	for(ll i=1;i<=n;i++) cin>>c[i];
	if(n<=10){
		for(ll i=1;i<=n;i++) p[i]=i;
		ll ans=0;
		do{
			tot=0;
			ll nc=0;
			for(ll i=1;i<=n;i++){
				if(c[p[i]]<=nc) nc++;
				else{
					if(s[i-1]=='0') nc++;
					else tot++;
				}
			}
			if(tot>=m) ans++;
		}while(next_permutation(p+1,p+n+1));
		cout<<ans<<"\n";
	}
	else if(tot==n){
		ll ls=1;
		for(ll i=1;i<=n;i++) ls=ls*i%mod;
		cout<<ls<<"\n";
	}
	else{
		cout<<"0\n";
	}
	return 0;
}
