//T1 number
#include <bits/stdc++.h>
using namespace std;
long long n, a[1234567], m, cnt;
string s;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	n = s.size();
	for(int i = 0; i < n; i++)if(s[i] >= '0' && s[i] <= '9')a[cnt++] = s[i] - '0';
	sort(a, a + cnt);
	for(int i = cnt - 1; i >= 0; i--)cout << a[i];
	return 0;
}
//我要吃麦当劳！
