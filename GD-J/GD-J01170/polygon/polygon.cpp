#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL n;
LL a[5010];
LL ans;

void dfs(LL id, LL m, LL cnt, LL mx){  // 第 id 个小木棍，使用 m 个，共 cnt 长度，最大为 m 
	if(id == n + 1) return;
	dfs(id + 1, m, cnt, mx); // 不选 
	m += 1, cnt += a[id], mx = max(mx,a[id]); 
	if(m > 2 && cnt > 2 * mx) ans++, ans %= 998244353;
	dfs(id + 1, m, cnt, mx); // 选 
	return;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	cin >> n;
	for(LL i = 1;i <= n;i++) cin >> a[i];
	dfs(1,0,0,0);
	cout << ans % 998244353;

	fclose(stdin);
	fclose(stdout);
	return 0;
}

