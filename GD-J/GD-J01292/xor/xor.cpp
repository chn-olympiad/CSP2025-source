#include <bits/stdc++.h>
using namespace std;
int n, s, br; long long a[500005], k;
struct ed{
	int l, r;
};
vector <ed> v;
bool cmp(ed a, ed b){
	if (a.l == b.l) return a.r - a.l < b.r - b.l;
	return a.l < b.l;
}
long long awyh(int l, int r){
	if (l == r) return a[l];
	long long s = a[l];
	for (int i = l + 1; i <= r; i++) s = (s ^ a[i]);
	return s;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
			if (awyh(i, j) == k) v.push_back({i, j});
	if (v.size() == 0){cout << 0; return 0;}
	sort(v.begin(), v.end(), cmp);
	br = v[0].r; s++;
	for (int i = 1; i < (int)v.size(); i++) if (v[i].l > br){s++; br = v[i].r;}
	cout << s;
	return 0;
}
