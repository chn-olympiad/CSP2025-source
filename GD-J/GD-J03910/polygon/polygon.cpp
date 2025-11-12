#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<vector>
#define ll long long
using namespace std;
/*
st+前缀和+dp
*/
const ll N=998244353;
ll n,ans;
vector<ll> num;
vector<ll> sum;
vector<vector<ll>> st;
ll getSum(ll l,ll r) {
	return sum[r]-sum[l-1];
}
ll getST(ll l,ll r) {
	return st[l][r];
}
void initST() {
	st.resize(n+1);
	for(ll l=1;l<=n;l++) {
		st[l].resize(n+1,0);
		for(ll r=l+1;r<=n;r++) {
			st[l][r]=max(st[l][r-1],num[r]);
		}
	}
}
bool check(ll l,ll r) {
	return (getSum(l,r)>getST(l,r)*2);
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	sum.push_back(0);
	num.push_back(0);
	for(ll i=0;i<n;i++) {
		ll x;
		cin>>x;
		sum.push_back(sum[i]+x);
		num.push_back(x);
	}
	initST();
	if(n<=3) {// dont touch! its magic!
		if(n==3) {
			cout<<check(1,3);
		}
		else {
			cout<<0;
		}
		return 0;
	}
	for(ll l=0;l<n;l++) {
		for(ll r=l;r<n;r++) {
			if(check(l,r)) ans=(ans+1)%N;
		}
	}
	cout<<ans;
	return 0;
}
/*
5
1 2 3 4 5
*/

// 预计得分12tps 
