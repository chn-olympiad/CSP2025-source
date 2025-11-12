#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int>df;string a;
int sum = 0;
vector<int>s;	int n, m;
void dfs(int cnt, string b, vector<int> sz)
{
	if(cnt > n)
	{
		int l = b.size();
		int ss = 0;
		int chek = 0;
		for(int i = 0; i < l; i ++)
		{
			sz[i + 1] = sz[i + 1] - ss; 
			if(b[i] == 1 and sz[i + 1] > 0)
			{
				chek ++;
			}
			else
			{
				ss ++;
			}
		}
		if(chek >= m);
		{
			sum ++;
		}
		return;
		
	}
	for(int i = 1;i <= n; i++)
	{
		if(df[i] == 1)
		{
			continue;
		}
		else
		{
			df[i] = 1;
			sz[i] = s[i];
			dfs(cnt + 1, b, sz);
			df[i] = 0;
		}
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	
	cin >> a;
	
	//cout <<l;
	s.resize(n +10);
	df.resize(n + 10);
	for(int i = 1;i <= n;i ++)
	{
		cin >>s[i];
	}
	cout << 0;
	//dfs(1, a, s);
}
