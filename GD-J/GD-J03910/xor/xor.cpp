#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cmath>
#define ll long long
using namespace std;
struct node {
	ll v,l,r;
};
ll n,k,ans;
vector<ll> num;
vector<node> w;
bool flag=true;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=0;i<n;i++) {
		ll x;
		scanf("%lld",&x);
		num.push_back(x);
		if(x!=1) flag=false;
	}
	if(n<=2) {// dont touch! its magic!
		if(n==1) cout<<(num[0]==k);
		else {
			if(num[0]==k && num[1]==k) cout<<2;
			else if(num[0]^num[1]==k || num[0]==k || num[1]==k) cout<<1;
			else cout<<0; 
		}
		return 0;
	}
	if(flag) {// dont touch! its magic! 
		cout<<n/2;
		return 0;
	}
	/* 01 背包 */
	
	/*
		总容量为 n 
		
		重量=价值？-不 
		 
		预处理可选择区间 
		重量=区间长度
		价值=1 ，所以不用v向量 
		
		可供选择的区间要暴力？也许
		but O(n^3)应该不会超 
	*/
	for(ll l=0;l<n;l++) {
		for(ll r=l;r<n;r++) {
			ll cnt=num[l];
			for(ll i=l+1;i<=r;i++) cnt=cnt^num[i];
			if(cnt==k) w.push_back({r-l+1,l,r});
		}
	}
//	for(ll i=0;i<w.size();i++) {
//		cout<<w[i].v<<"\n";
//	}
//	cout<<"\n";
	vector<node> dp(w.size());// dp[i]表示选择前i个数字获得的区间数量最大值
	for(ll i=0;i<w.size();i++) {// 物品 
		for(ll j=n;j>=w[i].v;j--) {// 重量 
			ll soc=dp[j-w[i].v].v+1;
			if(soc>=dp[i].v && (dp[i].r<w[i].l || dp[i].l>w[i].r)) {
				dp[i].v=soc;
				dp[i].l=w[i].l;
				dp[i].r=w[i].r;
			}
		}
	}
	cout<<dp[w.size()-1].v;
	return 0;
}
/*
4 2
2 1 0 3

4 3
2 1 0 3
*/

/*
101
^
000
=101

100
^
1
^
111
^
111
=000

*/

// 预计得分10tps 
