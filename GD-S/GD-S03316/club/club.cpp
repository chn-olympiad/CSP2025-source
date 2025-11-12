#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll T,a[100010][5],dp[101][101][101];
map<ll,ll>dpp[20001];
void solve(){
	ll n;
	cin>>n;
	bool b=0,c=0;
	for(ll i=1,x,y,z;i<=n;i++){
		for(ll j=1;j<=3;j++){
			cin>>a[i][j];
		}
		if(a[i][2]) b=1;
		if(a[i][3]) c=1;
	}
	if(n<=200){
		for(ll l=1;l<=n;l++){
			for(ll i=0;i<=min(l,n/2);i++){
				for(ll j=0;j<=min(l-i,n/2);j++){
					ll k=l-i-j;
					if(k>n/2) continue;
					ll s=0;
					if(i) s=max(s,dp[i-1][j][k]+a[l][1]);
					if(j) s=max(s,dp[i][j-1][k]+a[l][2]);
					if(k) s=max(s,dp[i][j][k-1]+a[l][3]);
					dp[i][j][k]=s;
				}
			}
		}
		ll ans=0;
		for(ll i=0;i<=n/2;i++){
			for(ll j=0;j<=min(n-i,n/2);j++){
				ll k=n-i-j;
				if(k>n/2) continue;
				ans=max(ans,dp[i][j][k]);
			}
		}
		cout<<ans<<"\n";
	}else if(!c){
		if(b==0){
			vector<ll>f;
			ll ans=0;
			for(ll i=1;i<=n;i++) f.push_back(a[i][1]);
			sort(f.begin(),f.end());
			for(ll i=1,l=f.size()-1;i<=n/2;i++,l--) ans+=f[l];
			cout<<ans<<"\n";
		}else{
			for(ll l=1;l<=n;l++){
				for(ll i=0;i<=min(l,n/2);i++){
					ll j=l-i;
					if(j>n/2) continue;
					ll s=0;
					if(i) s=max(s,dpp[i-1][j]+a[l][1]);
					if(j) s=max(s,dpp[i][j-1]+a[l][2]);
					dpp[i][j]=s;
				}
			}
			ll ans=0;
			for(ll i=0;i<=n/2;i++){
				ll j=n-i;
				if(j>n/2) continue;
				ans=max(ans,dpp[i][j]);
			}
			cout<<ans<<"\n";
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(nullptr),cout.tie(nullptr),ios::sync_with_stdio(false);
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
