#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned int UI;
typedef unsigned long long ULL;

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
#define x first
#define y second

const int N = 2e5 + 5;

int n, q;
string s1[N], s2[N];

LL res;

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n >> q;
	for (int i = 1; i <= n; i ++ ) cin >> s1[i] >> s2[i];
	
	while (q -- )
	{
		string t1, t2; cin >> t1 >> t2;
		
		res = 0;
		for (int i = 1; i <= n; i ++ )
			for (int j = 0; j < t1.size() - s1[i].size() + 1; j ++ )
				if (t1.substr(j, s1[i].size()) == s1[i])
				{
					string st = "";
					if (j > 0) st += t1.substr(0, j);
					st += s2[i];
					if (j + s1[i].size() < t1.size()) st += t1.substr(j + s1[i].size(), t1.size() - j - s1[i].size());
					if (st == t2) 
						res ++ ;
				}
		
		cout << res << '\n';
	}

	return 0;
}


