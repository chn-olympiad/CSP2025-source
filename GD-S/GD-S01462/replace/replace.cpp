#include <bits/stdc++.h>
using namespace std;

struct node
{
	string s1, s2;	
};
node a[200005];

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout)
	int n, q;
	cin >> n >> q;
	if(n <= 100)
	{
		for(int i = 1; i <= n; i++) cin >> a[i].s1 >> a[i].s2;
		for(int i = 1; i <= q; i++)
		{
			string t1, t2;
			cin >> t1 >> t2;
			int ans = 0;
			for(int j = 1; j <= n; j++)
			{
				string now1 = a[j].s1, now2 = a[j].s2;
				for(int k = 0; k < t1.size() - now1.size() + 1; k++)
					if(t1.substr(k, now1.size()) == now1 && t2.substr(k, now1.size()) == now2 && t1.substr(0, k) == t2.substr(0, k) && t1.substr(k + now1.size()) == t2.substr(k + now1.size()))	ans++;	
			}
			cout << ans << endl;
		}
	}
	else
	{
		for(int i = 1; i <= q; i++)	cout << 0 << endl;
	}
	return 0;
}
