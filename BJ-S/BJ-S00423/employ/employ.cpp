#include <bits/stdc++.h>
using namespace std;

int n,m,ans;
string s;
int d[505];
int c[505];
bool flag[505];

void dfs(int step)
{
	if(step == n + 1)
	{
		int f = 0;
		int cnt = 0;
		for(int i = 1;i <= n;i++)
		{
			int nw = d[i];
			if(c[nw] <= f)
			{
				f++;
//				cout << f << endl;
				continue ;
			}
			if(s[i - 1] == '0')
			{
				f++;
		//		cout <<f << " " << i << " " << nw << endl;
 				continue ;
			}
			else
			{
				cnt++;
			}
		}
		if(cnt >= m)
		{	
			ans++;
	//		for(int i = 1;i <= n;i++)
	//			cout << d[i] << " ";
	//		cout << "\n";
		}

		return ;
	}
	for(int i = 1;i <= n;i++)
	{
		if(flag[i]) continue;
		flag[i] = 1;

		d[step] = i;
		dfs(step + 1);
		flag[i] = 0;
		d[step] = 0;
	}
}

int main()
{

	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);

	cin >> n >> m;
	cin >> s;
	for(int i = 1;i <= n;i++)
	{
		cin >> c[i];
	}
	if(n <= 100)
	{
		dfs(1);
		cout << ans << "\n";		
	}
	else
	{
		cout << 0 << endl;
	}
	return 0;
}
