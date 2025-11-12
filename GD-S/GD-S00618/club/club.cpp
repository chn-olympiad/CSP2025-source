#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
#define endl '\n'

const int N = 1e5 + 10,M = 5;
int t,n,a[N][M],tot[M],tmp[N];

struct Bit
{
	int pos,x;
}maxer[M][N];

inline bool cmp(Bit x,Bit y)
{ return x.x < y.x; }

signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> t;
	while (t --)
	{
		tot[1] = tot[2] = tot[3] = 0;
		cin >> n;
		int ans = 0;
		for(int i = 1;i <= n;i ++) tmp[i] = 0;
		for(int i = 1;i <= n;i ++)
		{
			int maxn = 0,pos = -1;
			for(int j = 1;j <= 3;j ++)
			{
				cin >> a[i][j];
				if (maxn < a[i][j]) pos = j,maxn = a[i][j];
			}
			maxer[pos][++tot[pos]] = {i,maxn};
			ans += maxn;
		}
		int maxn = 0,pos = -1;
		for(int i = 1;i <= 3;i ++)
		{
			sort(maxer[i] + 1,maxer[i] + tot[i] + 1,cmp);
			if (tot[i] > maxn) maxn = tot[i],pos = i;
		}
		if (maxn <= n / 2)
		{
			cout << ans << endl;
			continue;
		}
		int cnt = tot[pos];
		for(int i = 1;i <= cnt;i ++)
		{
			tmp[i] = 0;
			for(int j = 1;j <= 3;j ++) 
			{
				if (j == pos) continue;
				tmp[i] = max(tmp[i],a[maxer[pos][i].pos][j]);
			}
			tmp[i] = maxer[pos][i].x - tmp[i];
		}
		sort(tmp + 1,tmp + cnt + 1);
		for(int i = 1;i <= cnt - n / 2;i ++) ans -= tmp[i];
		cout << ans << endl;
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




