#include <bits/stdc++.h>
using namespace std;
int n, k, a[5000005];
struct Area{
	int l, r;
}b[5000005];
long long cnt, num, ans;
bool cmp(Area x, Area y){
	if (x.r == y.r) return x.l < y.l;
	else return x.r < y.r;
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++){
		int sum = a[i];
		if (sum == k) b[++cnt].l = i, b[cnt].r = i;
		for (int j = i + 1; j <= n; j++){
			sum ^= a[j];
			if (sum == k) b[++cnt].l = i, b[cnt].r = j;
		}
	}
	sort(b + 1, b + cnt + 1, cmp);
	for (int i = 1; i <= cnt; i++){
		if (b[i].l > num){
			ans++;
			num = b[i].r;
		}
	}
	cout << ans;
	return 0;
}
