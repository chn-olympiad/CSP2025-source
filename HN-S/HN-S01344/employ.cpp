#include<bits/stdc++.h>
#define ll long long
#define bt(x) __builtin_popcount(x)

using namespace std;
const ll N=509,M=(1<<18),mod=998244353;
ll dp[19][M+9],c[N],n,m,ex[N],book[N];
string s;

inline void gx(ll &x,ll y){
	x=x+y;
	x%=mod;
}
inline ll ksm(ll x,ll y){
	ll res=1;
	while(y){
		if(y&1)res=res*x%mod;
		x=x*x%mod;y>>=1;
	}
	return res;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	if(m==n){
		if(m==n){
			for(int i=1;i<=n;i++)
				if(c[i]==0)
					return cout<<0,0;
			for(int i=0;i<s.size();i++)
				if(s[i]=='0')
					return cout<<0,0;
			ll ans=1;
			for(int i=1;i<=n;i++)
				ans=1ll*ans*i%mod;
			cout<<ans;
			return 0;
		}
	}
	dp[0][0]=1;
	ll ans=0;
	for(int j=0;j<(1<<n);j++)
		for(int i=0;i<=n;i++){
			if(j==(1<<n)-1){
				if(n-i>=m)
					ans+=dp[i][j];
				ans%=mod;
			}
			if(i==n) continue;
			for(int k=1;k<=n;k++)
				if(!((j>>k-1)&1)){
					int cost=i;
					if(s[bt(j)]=='0' || c[k]<=i)
						cost++;
					gx(dp[cost][j|(1<<k-1)],dp[i][j]);
				}
		}
	cout<<ans;
	return 0;
}
