#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
bool Custom_Cmp(int x, int y)
{
	return x > y;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s, ans;
	cin >> s;
	int n = s.size();
	for (int i = 0; i < n; i ++)
	{
		if (isdigit(s[i]))
		{
			ans = ans + s[i];
		}
	}
	sort(ans.begin(), ans.end(), Custom_Cmp);
	cout << ans;
	return 0;
}