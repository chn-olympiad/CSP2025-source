#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353, MAX = 510;
#define ll long long
int n;
ll ans = 0;
vector <int> a(MAX);
bool check(int now, vector <int> ch){
	if(now < 3) return false;
	ll sum = 0;
	int maxn = 0;
	for(int i = 0; i < now; i++){
		sum += ch[i];
		maxn = max(maxn, ch[i]);
	}
	if(sum > maxn * 2) return true;
	return false;
}
void dfs(int num, int now, vector <int> ch, bool flag){
	if(num > n + 1 || (now == 0 && num == n - 1)) return ;
	if(flag) if(check(now, ch)) ans = (ans + 1) % mod;
	dfs(num + 1, now, ch, false);
	ch.push_back(a[num]);
	dfs(num + 1, now + 1, ch, true);
	ch.pop_back();
	return ;
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	vector <int> ch;
	dfs(1, 0, ch, false);
	printf("%lld", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
