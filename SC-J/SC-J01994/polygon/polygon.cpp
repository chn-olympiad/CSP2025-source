#include<bits/stdc++.h>
const int N = 5e5;
int a[N], n;
int choice(int x) {
	int s = 0, b = 0;
	for (int j = 1; j <= x; j++)
		for (int i = 1; i <= n; i++) {
			b += a[i];
		}
	if (b >= a[1])
		s++;
	return s;
}
using namespace std;
int main() {
	freopen(" polygon.in","r",stdin);
	freopen(" polygon.out","w",stdout);
	int sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 3; i <= n; i++)
		sum += choice(i);
	cout << sum % 998 % 244 % 353;
	return 0;
}