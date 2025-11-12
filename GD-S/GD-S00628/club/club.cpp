#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 1;
typedef long long ll;
struct node{
	int my, ren, bm;
}a[maxn];
bool cmp(node x, node y) {
	if (x.my != y.my) return x.my > y.my;
	return x.ren < y.ren;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T;
	cin >> T;
	while (T--)	{
		int n;
		cin >> n;
		int t = 0;
		for (int i = 0; i < n; i++) {
			int b[3];
			for (int j = 0; j < 3; j++) {
				cin >> b[j];
				a[t].my = b[j], a[t].ren = i, a[t].bm = j;
				t++;
			}
		}
		sort(a, a + n * 3, cmp);
		int sum = 0;
		int v[3] = {0, 0, 0};
		bool f[n];
		memset(f, false, sizeof(f));
		int z = 0, bn = n / 2;
		for (int i = 0; z < n; i++) {
			if (!(v[a[i].bm] + 1 > bn || f[a[i].ren])) {
				sum += a[i].my;
		    	int x = a[i].bm, y = a[i].ren;
				v[x]++;
				f[y] = true, z++;
		    } 
		}
		cout << sum << endl;
	}
	return 0; 
}
