//T1(100)
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define lowbit(x) ((x)&(-(x)))
using namespace std;
const int N = 100010;

int T, n, a[N][5], mx[N], p[N];


void solve(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		mx[i] = -1, p[i] = 0;
		for (int j = 1; j <= 3; j++){
			scanf("%d", &a[i][j]);
			if (a[i][j] > mx[i])
				mx[i] = a[i][j], p[i] = j;
		}
	}
	//先是看看理论最优是否可行 
	int cnt[5];
	ll res = 0;
	bool fl = true;
	cnt[1] = cnt[2] = cnt[3] = 0;
	for (int i = 1; i <= n; i++){
		if (cnt[p[i]] < n / 2)
			cnt[p[i]]++, res += mx[i];
		else
			fl = false;
	}
	if (fl){//理论可行 
		printf("%lld\n", res);
		return ;
	}
	//接下来就要枚举哪个组是满的了 
	ll ans = 0;
	for (int k = 1; k <= 3; k++){
		if (k != 1){//把a[i][1]换成满的那个组的 
			for (int i = 1; i <= n; i++)
				swap(a[i][1], a[i][k]);
		}
		ll res = 0;
		vector<int> b;
		for (int i = 1; i <= n; i++){
			res += a[i][1];
			b.push_back(max(a[i][2], a[i][3]) - a[i][1]);
		}
		sort(b.begin(), b.end(), greater<int>());
		for (int i = 0; i < n / 2; i++)
			res += b[i];
		ans = max(ans, res);
	}
	printf("%lld\n", ans);
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	scanf("%d", &T);
	for (int it = 1; it <= T; it++)
		solve();
	return 0;
}
