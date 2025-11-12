#include<cstdio>
#include<iostream>
#include<algorithm>
#define int long long
using namespace std;

const int MOD = 998244353;

int a[5005], b[5005];
bool flag[5005];
int n, ans, t = 1, id;

void dfs(int d, int len){
	if (d > len){
		int maxn = 0, sum = 0;
		for (int i = 1;i <= len;i++){
			maxn = max(maxn, b[i]);
			sum += b[i];
		}
		if (maxn * 2 < sum){
			ans++;
			ans %= MOD;
		}
		return ;
	}
	for (int i = 1;i <= n;i++){
		if (flag[i] || a[i] < b[d-1] || i < d || (a[i] == b[d-1] && i == id)) continue;
		flag[i] = true;
		b[d] = a[i];
		id = i;
		dfs(d + 1, len);
		flag[i] = false;
		b[d] = 0; 
	}
	return ;
}


signed main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	scanf ("%lld", &n);
	bool fla = false;
	for (int i = 1;i <= n;i++){
		scanf ("%lld", &a[i]);
		if (a[i] != 1) fla = true;
	}
	if (fla == false){
		for (int i = n - 2;i >= 1;i--){
			for (int j = i;j >= 1;j--){
				ans += j;
			}
		}
		printf ("%lld\n", &ans);
		return 0;
	}
	sort (a + 1, a + 1 + n);
	for (int i = 3;i <= n;i++){
		dfs(1, i);
		t = 1;
	}
	printf ("%lld\n", ans % MOD);
	return 0;
}
