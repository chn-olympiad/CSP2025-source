#include<bits/extc++.h>
#define int long long
using namespace std;
using pii = pair<int,int>;
const int maxn = 1e5 + 5;
int n,ans;
int cnt[5];
pii a[maxn][5];
vector<int> b[5];
int read()
{
	int x = 0,f = 1;
	char ch = getchar();
	while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
	while (isdigit(ch)){x = x * 10 + (ch ^ 48); ch = getchar();}
	return x * f;
}
void solve()
{
	n = read(),ans = 0;
	for (int i = 1; i <= 3; i++)
		cnt[i] = 0,b[i].clear();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			a[i][j].first = read();
			a[i][j].second = j;
		}
		sort(a[i] + 1,a[i] + 4,greater<>());
		cnt[a[i][1].second]++,ans += a[i][1].first;
		b[a[i][1].second].push_back(a[i][2].first - a[i][1].first);
	}
	int pos = max_element(cnt + 1,cnt + 4) - cnt;
	sort(b[pos].begin(),b[pos].end(),greater<>());
	vector<int>::iterator p = b[pos].begin();
	int max1 = cnt[pos];
	while (max1-- > (n >> 1))
		ans += *p++;
	printf("%lld\n",ans);
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t = read();
	while (t--)
		solve();
	return 0;
}