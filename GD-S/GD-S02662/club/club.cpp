#include<bits/stdc++.h>
#define pa pair<int,int>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int N = 100010;
int n, a[N][3];
vector<pa>e[3];
int b[N], m;
void slove()
{
	for(int j = 0; j < 3; j++)e[j].clear();
	scanf("%d", &n);
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		int maxn = 0, mx = 0, id = 0;
		for(int j = 0; j < 3; j++)
		{
			scanf("%d", &a[i][j]);
			if(a[i][j] > maxn)mx = maxn, maxn = a[i][j], id = j;
			else if(a[i][j] > mx)mx = a[i][j];
		}
		e[id].push_back(mk(maxn, mx));
		ans += maxn;
	}
	for(int j = 0; j < 3; j++)
		if(e[j].size() > n / 2)
		{
			m = 0;
			for(pa to : e[j])
				b[++m] = to.fi - to.se;
			sort(b + 1, b + 1 + m);
			for(int j = 1; j <= m - n / 2; j++)
				ans -= b[j];
		}
	printf("%d\n", ans);
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t--)slove();
	return 0;
}
