#include "bits/stdc++.h"
#define ll long long
#define P pair<int, int>
using namespace std;
int n, q, len;
string a[100005], b[100005];
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i] >> b[i];
	}
	for(int i = 1;i <= q;i++)
	{
		string t1, t2;
		int ans = 0, st, ed;
		cin >> t1 >> t2;
		if(t1.size() != t2.size())
		{
			cout << 0 << '\n';
			continue;
		}
		for(int i = 0;i < (int)t1.size();i++)
		{
			if(t1[i] == t2[i])
			{
				continue;
			}
			st = i;
			break;
		}
		for(int i = (int)t1.size() - 1;i >= 0;i--)
		{
			if(t1[i] == t2[i])
			{
				continue;
			}
			ed = i;
			break;
		}
		for(int j = 1;j <= n;j++)
		{
			int f1 = int(t1.find(a[j])), f2 = int(t2.find(b[j]));
			//cout << f1 << ' ' << f2 << '\n';
			if(f1 == -1 || f2 == -1)
			{
				continue;
			}
			if(f1 == f2 && f1 <= st && f1 + (int)b[j].size() >= ed)
			{
				ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
