#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
struct node
{
	int c[4],id;
}ss[MAXN];
vector <int> vec[4];
inline int getdel(int x)
{
	int secmx = -1;
	for (int i = 1; i <= 3; i++)
	{
		if (i == ss[x].id) continue;
		secmx = max(secmx,ss[x].c[i]);
	}
	return ss[x].c[ss[x].id] - secmx;
}
inline bool cmp(const int tmpa,const int tmpb)
{
	return getdel(tmpa) < getdel(tmpb);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T,n;
	long long ans;
	cin >> T;
	while (T--)
	{
		cin >> n;
		ans = 0;
		for (int i = 1; i <= 3; i++) vec[i].clear();
		for (int i = 1,mx; i <= n; i++)
		{
			mx = -1;
			for (int j = 1; j <= 3; j++) cin >> ss[i].c[j],mx = max(mx,ss[i].c[j]);
			for (int j = 1; j <= 3; j++) if (mx == ss[i].c[j]) ss[i].id = j;
			vec[ss[i].id].push_back(i);
			ans += ss[i].c[ss[i].id];
		}
		for (int Id = 1; Id <= 3; Id++)
		{
			if (vec[Id].size() > n / 2)
			{
				sort(vec[Id].begin(),vec[Id].end(),cmp);
				for (int i = 1; i <= vec[Id].size() - n / 2; i++) ans -= getdel(vec[Id][i - 1]);
				break;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
