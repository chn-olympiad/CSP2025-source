#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 100;
int n, q;
struct str
{
	string s1, s2;
};
str a[N];
string s1, s2, s3, s4;
int cnt;
int ans;
bool cmp(str a, str b)
{
	return a.s1.size() < b.s1.size();
}
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].s1;
		cin >> a[i].s2;
	}
	sort(a + 1, a + 1 + n, cmp);
	while (q--)
	{
		ans = 0;
		cin >> s1;
		cin >> s2;
//		cout << endl;
		for (int i = 0; i < s1.size(); i++)
		{
			s3 = "";
			cnt = 1;
			for (int j = i; j < s1.size(); j++)
			{
				s3 += s1[j];
				while (s3.size() > a[cnt].s1.size() && cnt <= n) cnt++;
				while (s3.size() == a[cnt].s1.size())
				{
//					cout << cnt << endl;
					if (s3 == a[cnt].s1)
					{
						if (a[cnt].s2 == s2 && a[cnt].s1.size() == s1.size())
						{
							ans++;
							cnt++;
							continue;
						}
						s4 = "";
						for (int k = 0; k < i; k++) s4 += s1[k];
						s4 += a[cnt].s2;
						for (int k = j + 1; k < s1.size(); k++) s4 += s1[k];
	//					cout << s4 << " " << s2 << endl;
						if (s2 == s4) ans++;
					}
					cnt++;
					if (cnt > n) break;
				}
				if (cnt > n) break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
