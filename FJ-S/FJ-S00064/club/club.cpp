#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+10;
const int maxm=1e6+10;
const int mod=1e9+7;
int T,n,a[maxn][4],p[maxn],cnt[4],ans;
vector <int> g;
void solve()
{
	ans=0;
	memset(cnt,0,sizeof(cnt));
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		int mx=0;
		for (int j=1;j<=3;j++)
		{
			cin >> a[i][j];
			if (a[i][j]>mx) mx=a[i][j],p[i]=j;
		}
		cnt[p[i]]++;
		ans+=mx;
	}
	int d=0;
	if (cnt[1]>n/2) d=1;
	if (cnt[2]>n/2) d=2;
	if (cnt[3]>n/2) d=3;
	if (!d)
	{
		cout << ans << "\n";
		return;
	}
	g.clear();
	for (int i=1;i<=n;i++) if (p[i]==d)
	{
		sort(a[i]+1,a[i]+4);
		g.push_back(a[i][3]-a[i][2]);
	}
	sort(g.begin(),g.end());
	for (int i=0;i<cnt[d]-n/2;i++) ans-=g[i];
	cout << ans << "\n";
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> T;
	while (T--) solve();
	return 0;
}
/*
14:50 T1 100pts
15:14 T2 48pts
15:55 T4 20pts
16:38 T3 50pts
18:07 T4 24pts
100+48+50+24=222
*/
