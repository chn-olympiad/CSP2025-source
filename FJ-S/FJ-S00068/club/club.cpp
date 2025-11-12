#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+5;
int n,a[2][4];
ll ans;
vector <int> c[4];
int yq(int i)
{
	int maxn = max(max(a[i][1],a[i][2]),a[i][3]);
	if(maxn == a[i][1]) return 1;
	if(maxn == a[i][2]) return 2;
	if(maxn == a[i][3]) return 3;
}
void sol()
{
	for(int i=0;i<4;i++) c[i].clear();
	ans = 0;
	memset(a,0,sizeof(a));
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[1][1] >> a[1][2] >> a[1][3];
		int p = yq(1);
		int p1 = (p%3)+1;
		int p2 = (p1%3)+1;
		ans += a[1][p];
		c[p].push_back(min(a[1][p]-a[1][p1],a[1][p]-a[1][p2]));
		a[0][p] ++;
	}
	int p = yq(0);
	if(a[0][p] > (n/2))
	{
		sort(c[p].begin(),c[p].end());
		for(int i=0;i<(a[0][p]-(n/2));i++)
			ans -= c[p][i];
	}
	cout << ans << "\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--)
		sol();
	return 0;
}
