#include<bits/stdc++.h>
using namespace std;
int n, k, a[500005];
struct node{
	int start, end;
}p[500005];
bool cmp(node x, node y) {
	return x.end < y.end;
}
string cnt(int x) {
	string s = "";
	while(x != 0) {
		s = char(x % 2 + '0') + s;
		x /= 2;
	}
	return s;
}
int num(string s) {
	int k = -1, mul = 0;
	for (int i = s.size() - 1; i >= 0; i--) {
		k++;
		if (s[i] == '1') {
			mul += pow(2, k);
		}
	}
	return mul;
}
int yh(int x, int y) {
	string b = cnt(x), c = cnt(y), d = "";
	if (b.size() < c.size()) {
		for (int i = b.size() - 1; i <= c.size() - 1; i++) {
			b[i] = '#';
		}
	} else {
		for (int i = c.size() - 1; i <= b.size() - 1; i++) {
			c[i] = '#';
		}
	}
	for (int i = 0; i < max(b.size(), c.size()); i++) {
		if (b[i] != c[i]) d += '1';
		else d += '0';
	}
	return num(d);
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	if (k == 0) {
		cout << n / 2;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		int z = a[i];
		for (int j = i; j <= n; j++) {
			z = yh(z, a[j]);
			if (z == k)  {
				cnt++;
				p[cnt].start = i;
				p[cnt].end = j;
			}
		}
	}
	int ans = 0, e = 0;
	sort(p + 1, p + cnt + 1, cmp); 
	for (int i = 1; i <= cnt; i++) {
		if (p[i].start > e) {
			e = p[i].end;
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
