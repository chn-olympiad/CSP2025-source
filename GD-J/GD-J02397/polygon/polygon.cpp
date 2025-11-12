# include <bits/stdc++.h>
# define int long long
using namespace std;

int n,a[5005],per[5005];
const int MOD = 998244353;
bool all1 = true;
int ans = 0;
int edx,Max;

void dfs(int x,int cnt) 
{
	cnt += a[x];
	if (cnt > Max) {
		ans = (ans+1)%MOD;
	}
	for (int i = x+1;i <= edx;i ++) {
		dfs(i,cnt);
	}
}

signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i ++) {
		cin >> a[i];
		if (a[i] != 1) all1 = false;
	}
	if (n < 3) {
		cout << 0;
		return 0;
	}
	sort(a+1,a+1+n);
	if (n == 3) {
		if (a[1] + a[2] > a[3]) cout << 1;
		else cout << 0;
		return 0;
	}
	if (all1) {
		int ans = 1;
		for (int i = 1;i <= n;i ++) {
			ans = (ans * 2) % MOD;
		}
		int jian = 1 + n + n*(n-1)/2;
		jian %= MOD;
		ans = (ans + MOD - jian) % MOD;
		cout << ans;
		return 0;
	}
	for (int i = 1;i <= n;i ++) per[i] = per[i-1] + a[i];
	for (int i = 3;i <= n;i ++) {
		//for (int j = 1)
		edx = i-1;
		Max = a[i];
		dfs(0,0);
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
