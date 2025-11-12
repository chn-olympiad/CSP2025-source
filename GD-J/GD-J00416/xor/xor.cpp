#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll N = 5e5 + 10;
ll a[N],n,k, ans = 0, ok = 1;
map <ll, ll> mp;
bool ck(ll l, ll r){
	for(int i = l; i <= r; i++){
		if(mp[i] == 1) {
			for(int j = i - 1; j >= l; j--) mp[j] = 0;
		}
		else mp[i] = 1;
	}
	return false;
}
void solve(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] != 1) ok = 0;
		if(a[i] == k){
			mp[i] = 1;
			ans++;
			continue;
		}
	}
	if(ok && k == 0){
		cout << n / 2;
		return;
	}
	for(int l = 1; l <= n; l++){
		ll sum = a[l];
		for(int r = l + 1; r <= n; r++){
			sum = sum ^ a[r];
			if(sum == k && ck(l,r)){
				ans++;
				l = r + 1;
				break;
			} 
		}
	}
	cout << ans;
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int t = 1;
	while(t--) solve();
	return 0;
}
