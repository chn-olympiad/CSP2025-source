#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
string r[105][2];
void solve()
{
	string t1, t2;
	int ans = 0;
	cin >> t1 >> t2;
	for (int i = 1; i <= n; i++)
	{
		string temp1 = t1;
		for (int j = 0, to = t1.length() - r[i][0].length() + 1; j < to; j++)
		{
			bool flag = true;
			for (int k = 0, to2 = r[i][0].length(); k < to2; k++)
				if (r[i][0][k] != t1[j + k])
				{
					flag = false;
					break;
				}
//			cout << flag << '\n';
			if (flag)
				for (int k = 0, to2 = r[i][0].length(); k < to2; k++)
					t1[j + k] = r[i][1][k];
		}
//		cout << t1 << "*\n";
		if (t1 == t2)
			ans++;
		t1 = temp1;
	}
	cout << ans << '\n';
}
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> r[i][0] >> r[i][1];
	while (m--)
		solve(); 
}
