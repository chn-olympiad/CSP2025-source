#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 25;
ll a[N],bans;
ll n;

ll _pow(ll x){
	ll ans = 1;
	for(ll i = 1;i <= x;i ++){
		ans = (ans * 2) % 998244353;
	}
	return ans;
}

void dfs(ll t,ll cnt,ll maxx,ll sum){
	ll tmx = max(maxx,a[t]);
	if(cnt >= 2 and 2 * tmx < sum + a[t]) bans ++;
	if(t < n) dfs(t + 1,cnt + 1,tmx,sum + a[t]);
	if(t < n) dfs(t + 1,cnt,maxx,sum);
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin >> n;
	if(n > 20){
		cout << (_pow(n) - 1 - (n - 1) * n / 2 - n + 998244353) % 998244353;
	} else {
		for(ll i = 1;i <= n;i ++){
			cin >> a[i];
		}
		dfs(1,0,0,0);
		cout << bans;
	} 
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
