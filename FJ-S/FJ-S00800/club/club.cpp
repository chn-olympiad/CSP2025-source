#include <bits/stdc++.h>
#define ll long long
using namespace std;
constexpr int maxn = 1e5 + 5;
int n , cnt[4];
ll ans;
inline bool cmp1(pair<int , int> x , pair<int , int> y)
{
	return x.second < y.second;
}
struct node
{
	pair<int , int> p[4];
	p[0].second = -0x3f3f3f3f3f;
	int p4;
	inline void sort_it()
	{
		sort(p.begin() , p.end() , cmp1);
		ans += p[1].second;
		p4 = p[3].second - p[2].second;
		p[2].second = p[2].second - p[1].second;
		p[3].second = p[3].second - p[1].second;
	}
}a[maxn];
inline bool cmp2(node x , node y)
{
	return x.p4 > y.p4;
}
int main()
{
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t --)
	{
		ans = 0;
		cin >> n;
		for(int i = 1 ; i <= n ; i ++)
		{
			for(int j = 1 ; j <= 4 ; j ++)
			{
				int x;
				cin >> x;
				a[i].p[j].first = j;
				a[i].p[j].second = x; 
			}
			a[i].sort_it();
		}
		sort(a + 1 , a + n + 1 , cmp1);
		int i = 1;
		while(cnt[1] < n / 2 && cnt[2] < n / 2 && cnt[3] < n / 2)
		{
			cnt[a[i].p[3].first] ++;
			ans += a[i].p[3].second;
			i ++;
		}
		i ++;
		for(i ; i <= n ; i ++)
		{
			ans += a[i].p[2].second;
		}
		cout << ans << '\n';
	}
}
