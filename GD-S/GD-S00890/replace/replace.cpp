#include <bits/stdc++.h> 
#define int long long
using namespace std;

int n,q,res;

string s[200005],t[200005];
string changes[200005],changet[200005];

void dfs(string a,string b)
{
	if(a == b)
	{
		res++;
		return;
	}
	for(int i = 1;i <= q;i++)
	{
		if(a.find(changes[i]) < a.size())
		{
			string tmp = a;
			for(int x = a.find(changes[i]),j = 0;j < changet[i].size();x++,j++)
				a[x] = changet[i][j];
			dfs(a,b);
			a = tmp;
		}
	}
}

signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> q;
	
	for(int i = 1;i <= n;i++)
		cin >> s[i] >> t[i];
	for(int i = 1;i <= q;i++)
		cin >> changes[i] >> changet[i];
		
	for(int i = 1;i <= n;i++)
	{
		res = 0;
		dfs(s[i],t[i]);
		cout << res;
	}
}
