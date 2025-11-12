#include <bits/stdc++.h>
using namespace std;
int n, l[5001], cnt;
bool v[5001];
void dfs(int s, int maxn){
	if (s > 2 * maxn)cnt++;
	for (int i = 1; i <= n; i++){
		if (!v[i]){
			v[i] = 1;
			dfs(s + l[i], max(maxn, l[i]));
			dfs(s, maxn);
			v[i] = 0;
		}
	}
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	if (n < 3){
		cout << 0 << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++)cin >> l[i];
	dfs(0, 0);
	cout << cnt << endl;
	return 0;
}
