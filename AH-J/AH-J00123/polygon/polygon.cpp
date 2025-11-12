#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> p;
ll n,a[5005],dis[5005],sum1,sum2,num;
vector<p> g[5005];
//void Dijkstra 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]>a[3]) cout<<1;
		else cout<<0;
	}else{
		for(ll i=3;i<=n;i++){
			sum1=sum2=1;
			for(ll j=2;j<=n;j++) (sum1*=j)%=998244353;
			for(ll j=2;j<=i;j++) (sum2*=j)%=998244353;
			for(ll j=2;j<=n-i;j++) (sum2*=j)%=998244353;
			(num+=sum1/sum2)%=998244353;
		}
		cout<<num%998244353;
	}
	/*
	for(ll i=1;i<=n;i++){
		for(ll j=i+1;j<=n;j++){
			g[i].push_back({j,a[i]});
			g[i].push_back({j,a[j]});
			g[j].push_back({i,a[i]});
			g[j].push_back({i,a[j]});
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			if(i==j) continue;

		}
	}*/
	return 0;
}
