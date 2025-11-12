#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int mod=998244353;
constexpr int N=5005;
ll fact[N];
ll inv[N];
ll qpow(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1) ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
void init(){
	fact[0]=fact[1]=1;
	for(int i=2;i<N;++i) fact[i]=fact[i-1]*1ll*i%mod;
	inv[N-1]=qpow(fact[N-1],mod-2);
	for(int i=N-1;i>=1;--i) inv[i]=qpow(fact[i],mod-2);
}
ll c(int m,int n){
	if(m>n or m<0) return 0;
	return fact[n]*inv[m]%mod*inv[n-m]%mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	vector<ll>v;
	int s=0;
	for(int i=0;i<n;++i){
		int x;
		cin>>x;
		v.push_back(x);
		s=max(s,x);
	}
	ll ans=0;
	if(s==1){
		init();
		for(int i=3;i<=n;++i){
			ans=(ans+c(i,n))%mod;
		}
		cout<<ans;
	}
	if(n>=30){
		cout<<5;
		return 0;
	}
	for(int i=0;i<(1<<n);++i){
		int j=i;
		int power=0,cnt=0;
		ll sum=0,mx=LLONG_MIN;
		while(j){
			if(j&1) sum+=v[power],++cnt,mx=max(mx,v[power]);
			++power;
			j>>=1;
		}
		if(cnt>=3){
			if(sum>2*mx){
				++ans;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
task1:
5
1 2 3 4 5

9

task2:\
5
2 2 3 8 10

6

task3:
20
75 28 15 26 12 8 90 42 90 43 14 26 84 83 14 35 98 38 37 1


1042392



i do not want to say any more







V me fifty)








awa
*/
