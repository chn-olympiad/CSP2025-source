#include <bits/stdc++.h>
using namespace std;	
struct node {
	long long b;
	bool yes;
}p[2097200];
struct node1 {
	long long s, t;
};
long long n, k;
long long cnt, a[114514], ans;
bool cmp(node1 a, node1 b) {
	return a.t < b.t;
}
long long max_find(long long s, long long e) {
	if(s >= e) return 0;
	
	node1 f[10010];
	long long cnt = 0, max_f = 0;
	for(long long i = s - 1;i <= e;i ++) {
		if(p[a[i]^k].yes && p[a[i]^k].b > s && p[a[i]^k].b != i) {
		    f[++cnt].s = i + 1, f[cnt].t = p[a[i]^k].b;	
		}
	}
	sort(f + 1, f + cnt + 1, cmp);
	f[0].s = 0;
	f[1].s = 1;
	for(int i = 2;i <= cnt;i ++) {
		if(f[i].s > f[i - 1].t) {
			f[i].s = f[i - 1].s + 1;
		}
		else {
			f[i].s = f[i - 1].s;
			f[i].t = f[i - 1].t;
		}
	}
	return f[cnt].s;
}
int main() {
	freopen("xor.in","r", stdin);
	freopen("xor.out","w", stdout);
	cin >> n >> k;
	long long s = 1;
	for(int i = 1;i <= n;i ++) {
		long long x;
		cin >> x;
		if(x == k) {
			ans += 1;
			ans += max_find(s, i - 1);
			s = i + 1;
			a[i] = 0; 
			
		}
		else {
			a[i] = a[i - 1] ^ x;
			p[a[i]].yes = 1;
			p[a[i]].b = i;
		}
	}
	ans += max_find(s, n);
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
