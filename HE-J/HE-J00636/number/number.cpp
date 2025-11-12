#include <bits/stdc++.h>
using namespace std;
long long a[100000000];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	long long sum = 0;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[sum] = s[i] - '0';
			sum++;
		}
	}
	sort(a, a + sum);
	for (int i = sum - 1; i >= 0; i--) {
		cout << a[i];
    }
	return 0;
}
