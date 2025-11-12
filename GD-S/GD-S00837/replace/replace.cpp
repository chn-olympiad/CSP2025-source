#include<bits/stdc++.h>
#define LL long long
using namespace std;

const LL maxn = 2e5 + 5;
LL n, q;
string s[maxn][3], x, y;
struct node
{
	string s;
	LL num;
};
map <string, LL> mp;
LL dfs(string str)
{
	if(str == y)
	{
		return 1;
	}
	LL res = 0;
	for(int i = 1, pos; i <= n; i++)
	{
		pos = str.find(s[i][1]);
		if(pos != -1)
		{
			res += dfs(str.erase(pos, s[i][1].size()).insert(pos, s[i][2]));
		}
	}
	return res;
}

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
		cin >> s[i][1] >> s[i][2];
	while(q--)
	{
		mp.clear();
		cin >> x >> y;
		cout << dfs(x) << '\n';
	}
	return 0;
}
