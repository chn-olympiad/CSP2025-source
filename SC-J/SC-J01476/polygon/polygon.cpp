#include<bits/stdc++.h>
using namespace std;
const int N = 5e3+5;

int n, a[N], maxn;
long long cnt;
void func(int st, int x, int sum, int ma) {
	if (x == 0) {
		if (sum > ma * 2) {
			++cnt;
		}
		return;
	}
	for (int j = st; j <= n; ++j) {
		func(j + 1, x - 1, sum + a[j], max(ma, a[j]));
	}
	return;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		maxn = max(maxn, a[i]);
	}
	if(maxn==1){
		for(int j=1;j<n;j++){
			int x=n;
			for(int k=1;k<=j;++k){
				x=x*(n-k)%998244353;
			}
			cnt=(cnt+x)%998244353;
		}
		cout<<cnt;
		return 0;
	} 
	sort(a + 1, a + n + 1);
	for (int i = 3; i <= n; ++i) {
		func(1, i, 0, 0);
	}
	cout << cnt;
	return 0;
}