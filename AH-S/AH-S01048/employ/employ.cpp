#include<bits/stdc++.h>
using namespace std;
const int Mod = 998244353;
int n, m, c[505], vis[505], ans = 0, cnt = 0;
string s;
void dfs(int x, int sum, int lose) {
	if(sum >= m) {
		ans ++;
	}
	for(int i = 1; i <= n; i ++) {
		if(!vis[i] && lose < c[i]) {
			vis[i] = 1;
			if(s[x] == '1') {
				dfs(x + 1, sum + 1, lose);
			}else{
				dfs(x + 1, sum, lose + 1);
			}
			vis[i] = 0;
		}
	}
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	cin >> s;
	int k = s.size();
	for(int i = 1; i <= n; i ++) {
		scanf("%d", &c[i]);
	}
	for(int i = 0; i < k; i ++) {
		if(s[i] == '0') {
			cnt ++;
		}
	}
	if(n - cnt < m) {
		printf("0\n");
		return 0;
	}
	dfs(0, 0, 0);
	printf("%d\n", ans % Mod);
	return 0;
}
