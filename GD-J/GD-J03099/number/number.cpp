#include <bits/stdc++.h>
using namespace std;
string s;
int tot = 0, a[1000010];
bool cmp(int a, int b){return a > b;}
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++) if (s[i] >= '0' && s[i] <= '9') a[++tot] = s[i] - '0';
	sort(a + 1, a + 1 + tot, cmp);
	for (int i = 1; i <= tot; i++) cout << a[i];
}
