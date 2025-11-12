#include<bits/stdc++.h>
const int N = 1e5;
int a[N];
using namespace std;
int main() {
	freopen(" numbur.in","r",stdin);
	freopen(" numbur.out","w",stdout);
	string s;
	cin >> s;
	int n = s.size();
	for (int i = 1; i <= n; i++) {
		if (s[i] <= '9' && s[i] >= '0')
			a[i] = s[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = n; i >= 1; i--)
		cout << a[i] << " ";
	return 0;
}