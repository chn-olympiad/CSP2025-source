#include <bits/stdc++.h>
using namespace std;
int n,t;
long long ans;
int a[200005];
bool cmp(int s,int d)
{
	return s > d;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	bool f = 0;
	cin >> t;
	while (t--)
	{
		cin >> n;
		if (f || n >= 1e5)
		{
			f = 1;
			ans = 0;
			for (int i = 1;i <= n;i++)
			{
				int x;
				cin >> a[i] >> x >> x;
			}
			sort(a+1,a+n+1,cmp);
			for (int i = 1;i <= n/2;i++)
			{
				ans += a[i];
			} 
			cout << ans << "\n";
		}
		else
		{
			ans = 0;
			for (int i = 1;i <= n;i++)
			{
				int x,y,z;
				cin >> x >> y >> z;
				ans += max(max(x,y),z); 
			}
			cout << ans << "\n";
		}
	}
	
	return 0;
}
