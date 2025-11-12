#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 10121416;
int a[N];

struct node {
	int l,r;
} b[N],c[N];
map<int,int> mp;

bool cmp (node a, node b) {
	return a.r < b.r;
}

signed main () {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	int maxn = 0, num1 = 0, num0 = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 1) num1++;
		if (a[i] == 0) num0++;
		maxn = max(maxn,a[i]);
	}
	if (maxn <= 1) {
		if (k == 1) {
			cout << num1;
			return 0;
		}
		else {
			int zt = 0;
			for (int i = 1; i < n; i++) {
				if (a[i] == 1) zt++;
				if (a[i] == 0) zt = 0;
				if (zt == 2) {
					num0++;
					zt = 0;
				}
			}
			cout << num0;
			return 0;
		}
	}
	int t = 0;
	for (int i = 1; i <= n; i++) {
		int x = a[i];
		if (x == k) {
			b[++t].l = i;
			b[t].r = i;
			if (mp[i] == 0) mp[i] = i;
			else mp[i] = min(mp[i],i);
		}
		for (int j = i - 1; j >= 1; j--) {
			x ^= a[j];
			if (x == k) {
				b[++t].l = j;
				b[t].r = i;
				x = a[j - 1];
				if (mp[j] == 0) mp[j] = i;
				else mp[j] = min(mp[j],i);
				j--;
			}
		}
		x = a[i];
		for (int j = i + 1; j <= n; j++) {
			x ^= a[j];
			if (x == k) {
				b[++t].l = i;
				b[t].r = j;
				x = a[j + 1];
				if (mp[i] == 0) mp[i] = j;
				else mp[i] = min(mp[i],j);
				j++;
			}
		}
	}
	int j = 0;
	for (auto v:mp) {
		c[++j].l = v.first;
		c[j].r = v.second;
	}
	sort(c + 1, c + 1 + j, cmp);
	int idr = 0, sum = 0;
	for (int i = 1; i <= j; i++) {
		if (c[i].l > idr) {
			idr = c[i].r;
			sum++;
		}
	}
	cout << sum;
	return 0;
}
