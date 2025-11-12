#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+ 10;
long long n, k;
inline long long read() {
	long long f = 0;
	char t = getchar();
	while(t < '0' || t > '9') {
		t = getchar();
	}
	while(t >= '0' && t <= '9') {
		f = f * 10 + t - '0';
		t = getchar();
	}
	return f;
}
int a[N];
struct node{
	long long l, r;
};
node sum[N];
long long f[N], cnt;
bool cmp(node a, node b) {
	if(a.r != b.r) {
		return a.r < b.r;
	}
	return a.l > b.l;
}
vector<int>v[N];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);	
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		a[i] = read();
	}
	for(int i = 1; i <= n; i++) {
		long r = a[i];
		if(r == k) {
			sum[++cnt].l = i;
			sum[cnt].r = i;
			continue;
		}
		for(int j = i + 1; j <= n; j++) {
			r = r ^ a[j];
			if(r == k) {
				sum[++cnt].l = i;
				sum[cnt].r = j;
			}
		}
	}
	sort(sum + 1, sum + 1 + cnt, cmp);
	int c = 1;
	for(int i = 1; i <= cnt; i++) {
		v[sum[i].r].push_back(sum[i].l);
	}
	for(int i = 1; i <= n; i++) {
		f[i] = f[i - 1];
		for(int j = 0; j < v[i].size(); j++) {
			f[i] = max(f[i], f[v[i][j] - 1] + 1);
		}
	}
	long long y = 0;
	for(int i = 1; i <= n; i++) {
		y = max(y, f[i]);
	}
	cout << y;
	return 0;
}
