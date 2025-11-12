#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e3 + 15;
const ll mod = 998244353;
ll n,a[N],ans;
void dfs(ll x,ll maxn,ll sum,ll num){
	if(num >= 3){
		if(sum > maxn * 2){
			ans = (ans + 1) % mod;
		}
	}
	for(ll i = x + 1;i <= n;i ++){
		dfs(i,max(maxn,a[i]),sum + a[i],num + 1);
	}
	return ;
}
int main(){
//    freopen("polygon3.in","r",stdin);
//    freopen("xor.txt","w",stdout);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 1;i <= n;i ++){
    	cin >> a[i];
	}
	dfs(0ll,0ll,0ll,0ll);
	cout << ans;
    return 0;
}
