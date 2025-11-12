#include <bits/stdc++.h>
using namespace std;
string bina(int x) {
	string a;
	while (x) {
		a.push_back((x % 2) + '0');
		x /= 2;
	}
	return a;
}
int bor(string x,string y) {
	string a;
	string c;
	unsigned long long b = 0;
	if (x.size() > y.size()) {
		for (int i = y.size();i < x.size();i++) {
			y.push_back('0');
		}
	}else if (x.size() < y.size()) {
		for (int i = x.size();i < y.size();i++) {
			x.push_back('0');
		}
	}
	for (int i = 0;i < x.size();i++) {
		if (x[i] == y[i]) {
			c.push_back('0');
		}else {
			c.push_back('1');
		}
	}
	for (int i = c.size() - 1;i >= 0;i--) {
		b += (c[i] - '0') * pow(2,c.size() - 1 - i);
	}
	return b;
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	int xs[n + 5];
	for (int i = 0;i < n;i++) {
		cin >> xs[i];
	}
	int cnt = 0;
	for (int i = 0;i < n;i++) {
		int sum = xs[i];
		if (sum == k) {
			cnt++;
			continue;
		}
		for (int j = i;j < n - 1;j++) {
			sum += bor(bina(sum),bina(xs[j + 1]));
			if (sum == k) {
				cnt++;
				break;
			}
		}
	}
	cout << cnt;
	return 0;
} 
