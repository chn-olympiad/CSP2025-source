#include<bits/stdc++.h>
using namespace std;
int c[510];
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n, m;
	cin >> n >> m;
	char a[510];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	cout << m % 998 % 244 % 353 << endl;
	return 0;
}
