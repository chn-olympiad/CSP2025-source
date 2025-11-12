#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+3;
int a[maxn];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s, s1;
	cin >> s;
	if (s.size() == 1) {
		cout << s;
		return 0;
	}
	int k = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i]>='0' && s[i]<='9') {
			s[i] = s[i]-'a'+'0'+1;
			a[k] = s[i];
			k++;
		}
	}
	sort(a, a+k);
	for (int i = k-1; i >= 0; i--) cout << a[i];
	return 0;
}
