#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll a[25],b[25];
bool flag[25];
ll dp[20010][25];
ll fj(ll x){
	ll cnt=0;
	memset(flag,0,sizeof flag);
	ll p2=pow(2,20);
	for(ll i=20;i>=0;i--){
		if(x>=p2){
			x-=p2;
			flag[i+1]=1;
			cnt++;
		}
		if(x==0)break;
		p2/=2;
	}
	return cnt;
}
ll mod=998244353;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	for(ll i=1;i<=n;i++)cin>>b[i];
	dp[0][0]=1;
	ll maxsz=pow(2,n)-1;
	for(ll i=0;i<=n-1;i++){
		for(ll j=0;j<=maxsz;j++){
			
			ll opt=fj(j);
			if(opt!=i)continue;
			for(ll p=0;p<=i;p++){
				if(!dp[j][p])continue;
				for(ll add=1;add<=n;add++){
					
					if(flag[add])continue;
					ll pw=pow(2,add-1);
					ll newi=j|pw;
					if(a[i+1]==0)
						dp[newi][p]=(dp[newi][p]+dp[j][p])%mod;
					else if(i-p>=b[add])
						dp[newi][p]=(dp[newi][p]+dp[j][p])%mod;
					else 
						dp[newi][p+1]=(dp[newi][p+1]+dp[j][p])%mod;
				}
			}
		}
	}
	cout<<dp[maxsz][m];				
	return 0;
}
