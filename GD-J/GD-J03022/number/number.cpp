#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 10121416;
int a[N];

signed main () {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int j = 0;
	for (int i = 0; i < s.size(); i++)
		if (s[i] >= '0' && s[i] <= '9')
			a[++j] = s[i] - '0';
	sort(a + 1, a + 1 + j);
	for (int i = j; i >= 1; i--) cout << a[i];
	return 0;
}
