#include <iostream>
#include <cstring>

using namespace std;

const int N = 200010;

int n, q;
string sa[N], sb[N];
string s1, s2, q1, q2;

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n >> q;
	for (int i = 1; i <= n; i ++ )
		cin >> sa[i] >> sb[i];

	while (q -- )
	{
		int cnt = 0;
		cin >> s1 >> s2;
		q1 = s1, q2 = s2;
		for (int i = 1; i <= n; i ++ )
		{
			for (int j = 0; j < s1.size() - sa[i].size() + 1; j ++ )
			{
				bool flag = true;
				for (int k = 0; k < sa[i].size(); k ++ )
					if (s1[j + k] != sa[i][k]) { flag = false; break; }
				if (!flag) continue;
				for (int k = 0; k < sa[i].size(); k ++ ) s1[j + k] = sb[i][k];
				if (s1 == s2) cnt ++ ;
				s1 = q1;
			}
		}
		cout << cnt << endl;
	}

	return 0;
}