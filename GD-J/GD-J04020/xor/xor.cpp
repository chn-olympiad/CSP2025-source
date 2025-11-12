#include<bits/stdc++.h>
#define ll long long
#define N 1050007
#define max(a, b)((a)>(b)?(a):(b))
using namespace std;
int v[N];
ll n, k;
ll a[N], p[N];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for(int i = 0;i < N;i++){
		v[i] = -9999999;
	}
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		p[i] = p[i - 1] ^ a[i];
	}
	v[0] = 0;
	ll ans = 0;
	for(int i = 1;i <= n;i++){
		v[p[i]] = max(v[p[i]], v[p[i] ^ k] + 1);
		v[p[i]] = max(v[p[i]], ans);
		ans = max(ans, v[p[i]]);
	}
	cout << ans << '\n';
	
	return 0;
}
