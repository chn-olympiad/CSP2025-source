#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node
{
	int u;
	int o;
	int p;
};
int mx = 0;
void dfs(int cnt, vector<node> b, int h, int fl, vector<int> chek)
{
	
	if(h > fl)
	{
		//cout << cnt << h;
		for(int i = 1; i <= 3; i++)
		{
			if(chek[i] > fl / 2)
			{
				
				return;
			}
		}
		mx = max(cnt, mx);//cout << chek[3];
		return;
	}
	//dfs(cnt, b, h + 1, fl, chek, mx);
	for(int i = 1; i <= 3; i++)
	{
		
		if(i == 1)
		{
			chek[i] += 1;//cout  << 1;
			dfs(cnt + b[h].u, b, h + 1, fl, chek);
			chek[i] -= 1;
		}
		if(i == 2)
		{
			chek[i] += 1;
			dfs(cnt + b[h].o, b, h + 1, fl, chek);
			chek[i] -= 1;
		}
		if(i == 3)
		{
			chek[i] += 1;
			dfs(cnt + b[h].p, b, h + 1, fl, chek);
			chek[i] -= 1;
		}
		
	}
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int m;
		cin >> m;
		vector<node>clb(m + 10);
		vector<int>chk(5,0);
		for(int j = 1; j <= m; j++)
		{
			cin >> clb[j].u >> clb[j].o >> clb[j].p;
		}
		dfs(0, clb, 1, m, chk);
		cout << mx << endl;
		mx = 0;
	}
}
