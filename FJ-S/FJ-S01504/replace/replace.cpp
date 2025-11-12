#include <bits/stdc++.h>
using namespace std;

string s1[200005], s2[200005];
int n, q, ans = 0;
string t1, t2;
bool f[200005];

void dfs(int s, string t)
{
	if(t == t2)
	{
		ans++;
		return;
	}
	if(s > n)
	{
		return;
	}
	for(int j = 0; j < t.size() - s1[s].size() + 1; j++)
	{
		dfs(s + 1, t);
		for(int k = j; k <= j + s1[s].size() - 1; k++)
		{
			if(f[j])
			{
				dfs(s + 1, t);
				break;
			}
			if(k == j + s1[s].size() - 1 && t.substr(j, s1[s].size()) == s1[s])
			{
				dfs(s + 1, t.substr(0, j) + s2[s] + t.substr(j + s1[s].size(), t.size() - j - s1[s].size()));
				for(int x = j; x <= j + s1[s].size() - 1; x++)
				{
					f[j] = 1;
				} 
			} 
		}	
	}
}

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
	{
		cin >> s1[i] >> s2[i];
	}
	while(q--)
	{
		cin >> t1 >> t2;
		dfs(1, t1);
		cout << ans << endl;
		ans = 0;
	}
	return 0;
}
