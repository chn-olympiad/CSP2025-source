#include<bits/stdc++.h>
#define ll long long
#define N 5007
#define MOD 998244353
using namespace std;
int n;
ll a[N];
ll v[N * N], s[N * N];
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	int S = 0;
	for(int i = 1;i <= n;i++){
		S += a[i];
		for(int j = S - a[i];j >= a[i] + 1;j--){
			v[j + a[i]] += s[j];
			v[j + a[i]] %= MOD;
		}
		for(int j = S - a[i];j >= 1;j--){
			s[j + a[i]] += s[j];
			s[j + a[i]] %= MOD;
		}
		for(int j = 1;j < i;j++){
			s[a[i] + a[j]]++;
			s[a[i] + a[j]] %= MOD;
		}
	}
	int ans = 0;
	
	for(int i = 1;i <= S;i++){
		ans += v[i];
		ans %= MOD;
	}
	
	cout << ans << '\n';
	return 0;
}
