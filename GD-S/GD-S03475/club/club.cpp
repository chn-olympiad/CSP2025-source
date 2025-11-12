#include <iostream>
#include <vector>
using namespace std;
#define pii pair<int,int>
#define ll long long
const int N = 1e5+5;
int a[N][4];
pii p1[N],p2[N],p3[N];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			p1[i] = {0,0};
			p2[i] = {0,0};
			p3[i] = {0,0};
		}
		int cur1 = 0, cur2 = 0, cur3 = 0;
		ll ans = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			int maxn = max(a[i][1],max(a[i][2],a[i][3]));
			ans += maxn;
			if (maxn == a[i][1]) p1[++cur1] = {a[i][1],i};
			else if (maxn == a[i][2]) p2[++cur2] = {a[i][2],i};
			else p3[++cur3] = {a[i][3],i};
		}
		int cc1 = cur1;
		while (cur1 > n/2)
		{
			int minn = 1e9;
			int minc = 0, mint = 0;
			for (int i = 1; i <= cc1; i++)
			{
				if (p1[i].first == -1) continue;
				int id = p1[i].second;
				if (a[id][1] > a[id][2] && a[id][1]-a[id][2] < minn && cur2 < n/2)
				{
					minn = a[id][1]-a[id][2];
					minc = i;
					mint = 2;
				}
				if (a[id][1] > a[id][3] && a[id][1]-a[id][3] < minn && cur3 < n/2)
				{
					minn = a[id][1]-a[id][3];
					minc = i;
					mint = 3;
				}
			}
			p1[minc] = {-1,-1};
			cur1--;
			if (mint == 2) p2[++cur2] = {a[p1[minc].second][2],p1[minc].second};
			else if (mint == 3) p3[++cur3] = {a[p1[minc].second][3],p1[minc].second};
			ans -= minn;
		}
		int cc2 = cur2;
		while (cur2 > n/2)
		{
			int minn = 1e9;
			int minc = 0, mint = 0;
			for (int i = 1; i <= cc2; i++)
			{
				if (p2[i].first == -1) continue;
				int id = p2[i].second;
				if (a[id][2] > a[id][1] && a[id][2]-a[id][1] < minn && cur1 < n/2)
				{
					minn = a[id][2]-a[id][1];
					minc = i;
					mint = 1;
				}
				if (a[id][2] > a[id][3] && a[id][2]-a[id][3] < minn && cur3 < n/2)
				{
					minn = a[id][2]-a[id][3];
					minc = i;
					mint = 3;
				}
			}
			p2[minc] = {-1,-1};
			cur2--;
			if (mint == 1) p1[++cur1] = {a[p2[minc].second][1],p2[minc].second};
			else if (mint == 3) p3[++cur3] = {a[p2[minc].second][3],p2[minc].second};
			ans -= minn;
		}
		int cc3 = cur3;
		while (cur3 > n/2)
		{
			int minn = 1e9;
			int minc = 0, mint = 0;
			for (int i = 1; i <= cc3; i++)
			{
				if (p3[i].first == -1) continue;
				int id = p3[i].second;
				if (a[id][3] > a[id][1] && a[id][3]-a[id][1] < minn && cur1 < n/2)
				{
					minn = a[id][3]-a[id][1];
					minc = i;
					mint = 1;
				}
				if (a[id][3] > a[id][2] && a[id][3]-a[id][2] < minn && cur2 < n/2)
				{
					minn = a[id][3]-a[id][2];
					minc = i;
					mint = 2; 
				}
			}
			p3[minc] = {-1,-1};
			cur3--;
			if (mint == 1) p1[++cur1] = {a[p3[minc].second][1],p3[minc].second};
			else if (mint == 2) p2[++cur2] = {a[p3[minc].second][2],p3[minc].second};
			ans -= minn;
		}
		cout << ans << "\n";
	}
	return 0;
}
