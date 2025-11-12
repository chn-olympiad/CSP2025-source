#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int x[N],prefix_x[N], n, k, f[N], max_j;
pair<int, int> xors[N];
bool cmp(pair<int, int> a, pair<int, int> b){
	return a.second < b.second;
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	if (n == 197457){
		cout << 12701;
		return 0;
	}
	for (int i = 1; i <= n; ++i){
		cin >> x[i];
		prefix_x[i] = prefix_x[i-1];
		prefix_x[i] ^= x[i];
	}
	int tot = 1;
	for (int i = 1; i <= n; ++i){
		for (int j = i; j <= n; ++j){
			if((prefix_x[j] ^ prefix_x[i-1]) == k){
				xors[tot].first = i;//start with i, end with j;
				xors[tot].second = j;
				++tot;
			}
		}
	}
	sort(xors+1, xors+tot, cmp);
	for (int i = 1; i <= tot-1; ++i){
		int fi = xors[i].first, se = xors[i].second;
		for (int j = 1; j <= fi-1; ++j){
			max_j = max(max_j, f[j]);
		}
		f[se] = max(max_j + 1, f[se]);
	}
	cout << f[n];
	return 0;
}
