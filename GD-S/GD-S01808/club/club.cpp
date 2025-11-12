#include <bits/stdc++.h>
using namespace std;
struct Node
{
	int id;
	long long vala, valb;
} node[100005];
long long t, n, a[100005][5], maxx[100005], cnt[5], ans;
priority_queue<long long, vector<long long>, greater<long long> > quea, queb, quec;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t --)
	{
		cin >> n;
		for (int i = 1; i <= n; i ++)
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if (a[i][1] > a[i][2])
				maxx[i] = 1;
			else
				maxx[i] = 2;
			if (a[i][3] > a[i][maxx[i]])
				maxx[i] = 3;
			if (maxx[i] == 1)
				node[i].valb = max(a[i][2], a[i][3]);
			else if (maxx[i] == 2)
				node[i].valb = max(a[i][1], a[i][3]);
			else
				node[i].valb = max(a[i][1], a[i][2]);
			node[i].id = i;
			node[i].vala = a[i][maxx[i]];
		}
		cnt[1] = 0;
		cnt[2] = 0;
		cnt[3] = 0;
		ans = 0;
		while (quea.size())
			quea.pop();
		while (queb.size())
			queb.pop();
		while (quec.size())
			quec.pop();
		for (int i = 1; i <= n; i ++)
		{
			ans += node[i].vala;
			if (cnt[maxx[node[i].id]] < n / 2)
			{
				cnt[maxx[node[i].id]] ++;
				if (maxx[node[i].id] == 1)
					quea.push(node[i].vala - node[i].valb);
				else if (maxx[node[i].id] == 2)
					queb.push(node[i].vala - node[i].valb);
				else
					quec.push(node[i].vala - node[i].valb);
			}
			else
			{
				if (maxx[node[i].id] == 1)
				{
					quea.push(node[i].vala - node[i].valb);
					ans -= quea.top();
					quea.pop();
				}
				else if (maxx[node[i].id] == 2)
				{
					queb.push(node[i].vala - node[i].valb);
					ans -= queb.top();
					queb.pop();
				}
				else
				{
					quec.push(node[i].vala - node[i].valb);
					ans -= quec.top();
					quec.pop();
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
