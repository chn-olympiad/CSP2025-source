#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n, a[5005];
ll res;
const int mod = 998244353;
void dfs(int step, int maxn, int sum, int shu){
	if (step > n) return;
	shu++;
	sum += a[step];
	maxn = max(maxn, a[step]);
	if (shu >= 3 && maxn * 2 < sum){
		res++;
		res %= mod;
	}
	for (int i = step + 1; i <= n; i++){
		dfs(i, maxn, sum, shu);
	}
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++){
		dfs(i, 0, 0, 0);
	}
	cout << res;
	
	return 0;
}
