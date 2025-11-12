#include <bits/stdc++.h>
using namespace std;

int n, l[5000], vis[5000];
long long int cnt = 0;

void dfs(int deepth){
	if (deepth >= n){
		int maxx = INT_MIN, total = 0;
		for (int i=0;i<n;i++){
			if (vis[i] == 1) maxx = max(maxx, l[i]), total += l[i];
		}
		if (total > 2 * maxx) cnt++;
		return ;
	}
	vis[deepth] = 1;
	dfs(deepth+1);
	vis[deepth] = 0;
	dfs(deepth+1);
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i=0;i<n;i++) cin >> l[i];
	
	if (n <= 24){
		dfs(0);
		cout << cnt % 998244353 << endl;
	}else{
		for (int i=3;i<=n;i++){
			int tmp1 = 1, tmp2 = 1;
			for (int j=0;j<i;j++){
				tmp1 = (tmp1 * ((n - j) % 998244353)) % 998244353;
				tmp2 = (tmp2 * (j + 1)) % 998244353;
			}
			cnt = (cnt + ((tmp1 / tmp2) % 998244353)) % 998244353;
		}
		cout << cnt << endl;
	}
	
	return 0;
}
