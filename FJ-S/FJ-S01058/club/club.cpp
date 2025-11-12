#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define il inline
il int rd(){
	int s = 0, w = 1;
	char ch = getchar();
	for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') w = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar()) s = ((s << 1) + (s << 3) + ch - 48);
	return s * w;
}
const int N = 100005, INF = 1e9;
int n, a[N][3], cnt[3], typ[N], ans;
signed Main(){
	n = rd();
	for (int i = 1; i <= n; i++) for (int j = 0; j < 3; j++) a[i][j] = rd();
	cnt[0] = cnt[1] = cnt[2] = ans = 0;
	for (int i = 1; i <= n; i++){
		int t = max(a[i][0], max(a[i][1], a[i][2]));
		if (a[i][0] == t) cnt[0]++, typ[i] = 0;
		else if (a[i][1] == t) cnt[1]++, typ[i] = 1;
		else cnt[2]++, typ[i] = 2;
		ans += a[i][typ[i]];
	}
	int m = (n >> 1), tmp = -1;
	if (cnt[0] > m) tmp = 0;
	else if (cnt[1] > m) tmp = 1;
	else if (cnt[2] > m) tmp = 2;
	if (~tmp){
		vector <int> vec;
		for (int i = 1; i <= n; i++) if (typ[i] == tmp){
			int t = -1;
			for (int j = 0; j < 2; j++) if (j != tmp) t = max(t, a[i][j]);
			vec.push_back(a[i][tmp] - t);
		}
		sort (vec.begin(), vec.end());
		for (int i = 0; i < cnt[tmp] - m; i++) ans -= vec[i];
	}
	printf ("%d\n", ans);
	return 0;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	for (int T = rd(); T--;) Main();
	return 0;
}

