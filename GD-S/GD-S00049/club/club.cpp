//T1 = 5+10+5 = 20pts
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5, M = 1e4+5;
int n, m;
struct node
{
	int x, y, z;
}a[N];
int f[N];
bool cmp(node x, node y)
{
	if(x.x == y.x)
	{
		if(x.y == y.y)
		{
			return x.z > y.z;
		}
		return x.y > y.y;
	}
	return x.z > y.z;
}
bool cmp1(node x, node y)
{
	return x.x > y.x;
}
bool cmp2(node x, node y)
{
	return x.y > y.y;
}
bool cmp3(node x, node y)
{
	return x.z > y.z;
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		bool all230 = 1, all120 = 1, all130 = 1;
		bool all10 = 1, all20 = 1, all30 = 1;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i].x >> a[i].y >> a[i].z;
			if(a[i].y || a[i].z) all230 = 0;
			if(a[i].x || a[i].z) all130 = 0;
			if(a[i].y || a[i].x) all120 = 0;
			if(a[i].x) all10 = 0;
			if(a[i].y) all20 = 0;
			if(a[i].z) all30 = 0;
		}
		if(all230 || all120 || all130)
		{
			sort(a+1, a+n+1, cmp);
			int ans = 0;
			if(all120)
			for(int i = 1; 2 * i <= n; i++)
			{
				ans += a[i].z;
			}
			if(all130)
			for(int i = 1; 2 * i <= n; i++)
			{
				ans += a[i].y;
			}
			if(all230)
			for(int i = 1; 2 * i <= n; i++)
			{
				ans += a[i].x;
			}
			cout << ans << endl;
			continue;
		}
		if(all10)
		{
			int ans1 = 0, ans2 = 0;
			sort(a+1, a+n+1, cmp2);
			for(int i = 1; i <= n/2; i++)
			{
				ans1 += a[i].y;
			}
			sort(a+n/2+1, a+n+1, cmp3);
			for(int i = n/2+1; i <= n; i++)
			{
				ans1 += a[i].z;
			}

			sort(a+1, a+n+1, cmp3);
			for(int i = 1; i <= n/2; i++)
			{
				ans2 += a[i].z;
			}
			sort(a+n/2+1, a+n+1, cmp2);
			for(int i = n/2+1; i <= n; i++)
			{
				ans2 += a[i].y;
			}

			cout << max(ans1, ans2) << endl;
		}
		if(all20)
		{
			int ans1 = 0, ans2 = 0;
			sort(a+1, a+n+1, cmp1);
			for(int i = 1; i <= n/2; i++)
			{
				ans1 += a[i].x;
			}
			sort(a+n/2+1, a+n+1, cmp3);
			for(int i = n/2+1; i <= n; i++)
			{
				ans1 += a[i].z;
			}

			sort(a+1, a+n+1, cmp3);
			for(int i = 1; i <= n/2; i++)
			{
				ans2 += a[i].z;
			}
			sort(a+n/2+1, a+n+1, cmp1);
			for(int i = n/2+1; i <= n; i++)
			{
				ans2 += a[i].x;
			}

			cout << max(ans1, ans2) << endl;
		}
		if(all30)
		{
			int ans1 = 0, ans2 = 0;
			sort(a+1, a+n+1, cmp1);
			for(int i = 1; i <= n/2; i++)
			{
				ans1 += a[i].x;
			}
			sort(a+n/2+1, a+n+1, cmp2);
			for(int i = n/2+1; i <= n; i++)
			{
				ans1 += a[i].y;
			}

			sort(a+1, a+n+1, cmp2);
			for(int i = 1; i <= n/2; i++)
			{
				ans2 += a[i].y;
			}
			sort(a+n/2+1, a+n+1, cmp1);
			for(int i = n/2+1; i <= n; i++)
			{
				ans2 += a[i].x;
			}

			cout << max(ans1, ans2) << endl;
		}
		if(all10 || all20 || all30) continue;
		
	}
	
	return 0;
 } 
