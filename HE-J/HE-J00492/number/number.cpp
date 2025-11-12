#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 1e6 + 5;
char s[N];
int num[N], cnt = 0;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> s + 1;
	int n = strlen(s + 1);
	for (int i = 1; i <= n; i++)
	{
		char c = s[i];
		if (c <= '9' && c >= '0')
			num[++cnt] = (c - '0');
	}
	sort(num + 1, num + cnt + 1);
	for (int i = cnt; i >= 1; i--)
		cout << num[i];
	cout << endl;
	return 0;
}
