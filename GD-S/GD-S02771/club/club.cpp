#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e5 + 10;
int n,a[maxn][3],cnt[3];
struct node{int val1,val2;};
bool operator<(const node &p,const node &q){return max(p.val1,p.val2) < max(q.val1,q.val2);}
int get(int type)
{
	int sum = 0;priority_queue<node> q;cnt[0] = cnt[1] = cnt[2] = 0;cnt[type] = n;
	for(int i = 1;i <= n;i++)sum += a[i][type];
	for(int i = 1;i <= n;i++)q.push({-a[i][type] + a[i][(type + 1) % 3],-a[i][type] + a[i][(type + 2) % 3]});
	while(max(q.top().val1,q.top().val2) > 0 && !q.empty())
	{
		if(q.top().val1 > q.top().val2)
		{
			if(cnt[(type + 1) % 3] + 1 < cnt[type] - 1)
			{
				cnt[(type + 1) % 3]++;cnt[type]--;
				sum += max(q.top().val1,q.top().val2);
			}
			q.pop();
		}
		else
		{
			if(cnt[(type + 2) % 3] + 1 < cnt[type] - 1)
			{
				cnt[(type + 2) % 3]++;cnt[type]--;
				sum += max(q.top().val1,q.top().val2);
			}
			q.pop();
		}
	}
	while(cnt[type] > n / 2)sum += max(q.top().val1,q.top().val2),cnt[type]--,q.pop();
	return sum;
}
void solve()
{
	cin >> n;
	for(int i = 1;i <= n;i++)cin >> a[i][0] >> a[i][1] >> a[i][2];
	cout << max({get(0),get(1),get(2)}) << '\n';
}

signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;cin >> T;
	while(T--)solve();
	return 0;
}
/*
考虑去枚举人最多的是哪一种。 
*/
