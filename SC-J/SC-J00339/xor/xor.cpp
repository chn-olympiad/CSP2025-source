#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 10, MAXM = 2e6 + 10;
struct Node{
	int l, r;
}b[MAXN];
int a[MAXN], st[MAXN][25], pre[MAXN][25];
vector <int> ind[MAXM];
bool cmp(Node x, Node y){
	if (x.r != y.r) return x.r < y.r;
	else return x.l < y.l;
}
void calc(int id, int x){
	int cnt = 0;
	while (x){
		st[id][cnt] = (x & 1);
		x >>= 1;
		cnt++;
	}
	return;
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		calc(i, a[i]);
	}
	calc(n + 1, k);
	for (int i = 1; i <= n; i++){
		for (int j = 0; j <= 20; j++){
			pre[i][j] = pre[i - 1][j] + st[i][j];
		}
	}
	for (int i = 1; i <= n; i++){
		int tag = 0;
		for (int j = 20; j >= 0; j--){
			tag = tag * 2 + (pre[i][j] & 1);
		}
		ind[tag].push_back(i);
	}
	int m = 0;
	for (int i = 1; i <= n; i++){
		int tag = 0;
		for (int j = 20; j >= 0; j--){
			tag = tag * 2 + (1 - ((pre[i - 1][j] & 1) == st[n + 1][j]));
		}
		int len = ind[tag].size();
		if (len == 0 || ind[tag][len - 1] < i){
			continue;
		}
		int pos = *lower_bound(ind[tag].begin(), ind[tag].end(), i);
		b[++m].l = i, b[m].r = pos;
	}
	sort(b + 1, b + m + 1, cmp);
	int last = -1, ans = 0;
	for (int i = 1; i <= m; i++){
		if (b[i].l > last){
			last = b[i].r;
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}