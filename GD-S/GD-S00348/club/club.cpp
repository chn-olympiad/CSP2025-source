//canpass: all
#include <bits/stdc++.h>
#define int long long
#define rep1(i,a,b) for (int i = (a);i <= (b);i++)
using namespace std;
const int N = 1e5 + 10;
int n,ans;
int a[N][3],mx[N],mx2[N],buc[3];
pair<int,int> tmp[3];
void solve()
{
	cin >> n;
	rep1(i,1,n)
		rep1(j,0,2)
			cin >> a[i][j];
	//先对每个人贪心
	//如果最大值数量>n/2，就扔掉一些人，也贪心
	memset(buc,0,sizeof buc);
	ans = 0;
	rep1(i,1,n)
	{
		rep1(j,0,2)
			tmp[j] = {a[i][j],j};
		sort(tmp,tmp + 3);
		mx[i] = tmp[2].second;
		mx2[i] = tmp[1].second;
		buc[mx[i]]++;
		ans += tmp[2].first;
	}
	int mxx = 0;
	rep1(j,1,2)
		if (buc[j] > buc[mxx])
			mxx = j;
	if (buc[mxx] > n / 2)
	{
		int _ = buc[mxx] - n / 2;
		priority_queue<int,vector<int>,greater<int>> q;
		rep1(i,1,n)
			if (mx[i] == mxx)
				q.push(a[i][mx[i]] - a[i][mx2[i]]);
		rep1(i,1,_)
		{
			ans -= q.top();
			q.pop();
		}
	}
	cout << ans << '\n';
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while (t--)
		solve();
}
