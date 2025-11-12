#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int res;
string s[N], s2[N], l, ll, l2;
int n ,q, cnt;
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i ++ )
	{
		cin >> s[i] >> s2[i];
	}
	while (q -- ) 
	{
		cin >> l >> l2;
		
		
		res = 0;
		for (int i = 1; i <= n; i ++ )
		{
			int t;
			ll = l.c_str();
			while ((t = ll.find(s[i])) < l.size())
			{
				
				res ++ ;
				for (int x = 0; x < l.size(); x ++ )
				{
					if (x < t)
					{
						if (l[x] != l2[x]) 
						{
							res -- ;
							break;
						}
					}
					else if (x >= t && x < t + s2[i].size())
					{
						if (s2[i][x - t] != l2[x]) 
						{
							res -- ;
							break;
						}
					}
					else 
					{
						if (l[x] != l2[x]) 
						{
							res -- ;
							break;
							
						}
					}
				}
				ll[t] = '*';
//				cout << ll << '\n';
//				cnt ++ ;
//				if (cnt == 100) return 0;
			}
			
		}
		cout << res << '\n';
	}
	return 0;
}