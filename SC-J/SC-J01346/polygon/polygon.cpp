#include<bits/stdc++.h>
using namespace std;

void setup() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out","w",stdout);
}
vector<int> a;
int n;
bool checker(int l ,int r) {
	int aln = 0;
	int m = 0;
	if (r - l + 1 < 3) return 0;
//	cout << "checker():" <<l<<" " <<r<<"\n";
	for (int i=l;i<r;i++) {
//		cout << "checker():for(;;;)" << a[i] << \
			" " << m << " " << aln << "\n";
		m = max(m , a[i]);
		aln += a[i];
	}
//	cout << "checker():return ..." << (m * 2 < aln) << "\n";
	return m * 2 < aln;
}
int main() {
    setup();
	scanf("%d", &n);
	a.resize(n);
	a.reserve(0);
	for (int i=0;i<n;i++) {
		int tmp;
		scanf("%d", &tmp);
		a[i] = tmp;
	}
	int ans = 0;
	for (int i=0;i<n;i++) {
		for (int j=i;j<n;j++) {
			ans = (ans+checker(i, j)) % 998244353;
		}
	}
	printf("%d", ans);
    return 0;
}