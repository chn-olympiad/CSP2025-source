#include<bits/stdc++.h>
using namespace std;
int n,cnt;
long long a[5001];
vector<int> p;
void dfs(int x)
{
	if(x > n)
	{
		long long ans = 0;
		long long bg = 0;
		for(int i = 0;i < p.size();i ++)
		{
			//cout << p[i] << " ";
			if(p[i] == 1)
			{
				ans += a[i + 1];
				bg = max(bg,a[i + 1]);
			}
		
		}
		if(ans > bg * 2)
		{
			cnt ++;
			//cout << "++" << endl;
		}
		//cout << endl;
		p.pop_back();
		return;
	}
	for(int i = 0;i < 2;i ++)
	{
		p.push_back(i);
		dfs(x + 1);
	}
	p.pop_back();
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i ++)
	{
		cin >> a[i];
	}
	dfs(1);
	//cout << ((cnt % 998) % 244) % 353;
	cout << cnt;
	return 0; 
}
