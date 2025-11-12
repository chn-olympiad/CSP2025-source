#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][5],ans;
vector<int> v[5];
bool cmp(int x,int y)
{
	return a[x][3] - a[x][2] < a[y][3] - a[y][2];
}
void init()
{
	ans = 0;
	for(int i = 1; i <= 3; i++) v[i].clear();
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--)
	{
		init();
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		for(int i = 1; i <= n; i++)
		{
			int id = 1;
			for(int j = 1; j <= 3; j++) if(a[i][j] > a[i][id]) id = j;
			v[id].push_back(i);
			ans += a[i][id];
			sort(a[i] + 1,a[i] + 3 + 1);
		}
		for(int i = 1; i <= 3; i++)
		{
			if(v[i].size() > n/2)
			{
				sort(v[i].begin(),v[i].end(),cmp);
				for(int j = 0; j < v[i].size()-n/2; j++)
				{
					int x = v[i][j];
					ans -= a[x][3] - a[x][2];
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
