#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
int to(char x)
{
	return x - 'a';
}
struct ACAM
{
	struct node
	{
		int ch[30], fd;
		vector<int> id;
	} tr[5000011];
	int rt = 0, ct = 0;
	int newnode()
	{
		return ++ct;
	}
	void insert(string s, int id)
	{
		int u = rt;
		for (char c : s)
		{
			if (!tr[u].ch[to(c)])
				tr[u].ch[to(c)] = newnode();
			u = tr[u].ch[to(c)];
		}
		tr[u].id.push_back(id);
	}
	set<pii> find(string s)
	{
		set<pii> res;
		int u = 0;
		for (int i = 0; i < s.size(); i++)
		{
			char c = s[i];
			u = tr[u].ch[to(c)];
			int tp = u;
			while (tp)
			{
				for (int x : tr[tp].id)
					res.insert(make_pair(i, x));
				tp = tr[tp].fd;
			}
		}
		return res;
	}
	void bfs()
	{
		queue<int> q;
		for (int i = 0; i < 26; i++)
		{
			if (tr[rt].ch[i])
			{
				int ch = tr[rt].ch[i];
				tr[ch].fd = 0;
				q.push(ch);
			}
		}
		while (q.size())
		{
			int f = q.front();
			q.pop();
			for (int j = 0; j < 26; j++)
			{
				int &ch = tr[f].ch[j];
				int fd = tr[f].fd;
				if (!ch)
				{
					ch = tr[fd].ch[j];
					continue;
				}
				q.push(ch);
				tr[ch].fd = tr[fd].ch[j];
			}
		}
	}
}ac1, ac2;
int n, q;
int sz[200011];
string t1, t2, s1, s2;
string z1, z2;
struct range
{
	int l, r, id;
};
vector<range> rg;
int ans[200011];
int qq = 0;
signed main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> s1 >> s2;
		sz[i] = s1.size();
		ac1.insert(s1, i);
		ac2.insert(s2, i);
	}
	ac1.bfs();
	ac2.bfs();
	for (int i = 1; i <= q; i++)
	{
		int res = 0;
		cin >> t1 >> t2;
		int dl = -1, dr = 0;
		for (int i = 0; i < t1.size(); i++)
			if(t1[i] != t2[i])
			{
				if (dl < 0)
					dl = i;
				dr = i;
			}
		rg.push_back({dl + z1.size(), dr + z2.size(), i});
		z1 += t1;
		z1 += 'z' + 1;
		z2 += t2;
		z2 += 'z' + 1; 
	}
	auto r1 = ac1.find(z1);
	auto r2 = ac2.find(z2);
	cerr << "end";
	for (auto x : r2)
	{
		if (r1.find(x) != r1.end())
		{
			int r = x.first;
			int id = x.second;
			int l = r - sz[id] + 1;
			while (rg[qq].r <= r)
				qq++;
			qq--;
			if (rg[qq].l >= l)
				ans[rg[qq].id]++;
		}
	}
	for (int i = 1; i <= q; i++)
		cout << ans[i] << '\n';
	return 0;
}

