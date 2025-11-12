#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e5+5;
struct node {int v1,v2,v3;} a[N];
int T,n,ans,cntmx1,cntmx2,cntmx3;
priority_queue<int>fickle;

void solve()
{
	if(cntmx2 >= cntmx1 && cntmx2 >= cntmx3) for(int i = 1;i <= n;i++) swap(a[i].v1,a[i].v2);
	if(cntmx3 >= cntmx1 && cntmx3 >= cntmx2) for(int i = 1;i <= n;i++) swap(a[i].v1,a[i].v3);
	while(fickle.size()) fickle.pop();
	for(int i = 1;i <= n;i++)
	{
		if(a[i].v1 > a[i].v2 && a[i].v1 > a[i].v3 && fickle.size() < n/2)
		{
			ans += a[i].v1;
			fickle.push(max(a[i].v2,a[i].v3)-a[i].v1);
		}else if(a[i].v2 > a[i].v1 && a[i].v2 > a[i].v3) ans += a[i].v2;
		else if(a[i].v3 > a[i].v1 && a[i].v3 > a[i].v2) ans += a[i].v3;
		else if(a[i].v1 == a[i].v2 && a[i].v2 == a[i].v3) ans += a[i].v3;
		else
		{
			if(a[i].v2 == a[i].v3 && a[i].v2 > a[i].v1) ans += max(a[i].v2,a[i].v3);
			else if(fickle.size() && fickle.top()+a[i].v1 > max(a[i].v2,a[i].v3))
			{
				ans += fickle.top()+a[i].v1;
				fickle.pop();
				fickle.push(max(a[i].v2,a[i].v3)-a[i].v1);
			}else ans += max(a[i].v2,a[i].v3);
		}
	}
	return;
}

signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n;
		for(int i = 1;i <= n;i++) cin >> a[i].v1 >> a[i].v2 >> a[i].v3;
		cntmx1 = cntmx2 = cntmx3 = ans = 0;
		for(int i = 1;i <= n;i++)
		{
			if(a[i].v1 >= a[i].v2 && a[i].v1 >= a[i].v3) cntmx1++;
			else if(a[i].v2 >= a[i].v1 && a[i].v2 >= a[i].v3) cntmx2++;
			else if(a[i].v3 >= a[i].v1 && a[i].v3 >= a[i].v2) cntmx3++;
		}
		solve();
		cout << ans << '\n';
	}
	return 0;
}
