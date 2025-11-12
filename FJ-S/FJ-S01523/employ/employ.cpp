#include<bits/stdc++.h>
using namespace std;
int n, m, s[505], c[505], p[505], ans;
const int mod = 998244353;
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1, x; i <= n; i++)
		scanf("%1d", &x), s[i] = s[i - 1] + (x ^ 1);
	for(int i = 1; i <= n; i++) scanf("%d", &c[i]);
	for(int i = 1; i <= n; i++) p[i] = i;
	do{
		int cnt = 0;
		for(int i = 1; i <= n; i++) if(s[i] > s[i - 1] || c[p[i]] <= cnt) cnt++;
		if(n - cnt >= m) ans++;
	}while(next_permutation(p + 1, p + n + 1));
	printf("%d", ans);
	return 0;
}

