#include <iostream>
#include <cstring>
using namespace std;
int a[500005];
//int vis[500005];
//int vis1[500005];
int main()
{
	freopen("xor.in", "r" , stdin);
	freopen("xor.out", "w", stdout);
	int n, k, ans = 0;
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	if(k == 0)
	{
		bool flag = true;
		int aa = 0;
		for(int i = 1; i <= n; i++)
		{
			if(a[i] == 0)
			{
				aa++;
				flag = false;
			}
		}
		if(flag)
		{
			cout << "0";
			return 0;
		}
		else
		{
			cout << aa;
			return 0;
		}
		
	}
	if(k == 1)
	{
		bool flag = true;
		int bb = 0;
		for(int i = 1; i <= n; i++)
		{
			if(a[i] == 1)
			{
				bb++;
				flag = false;
			}
		}
		if(flag)
		{
			cout << "0";
			return 0;
		}
		else
		{
			cout << bb;
			return 0;
		}
		
	}
	for(int len = 1; len <= n; len++)
	{
		int maxn = 0;
		for(int i = 1; i <= n; i++)
		{
			int xsum = a[i];
//			vis[i] = 1;
			for(int j = i + 1; j <= i + len - 1 && j <= n; j++)
			{
				xsum = xsum xor a[j];
//				vis[j] = 1;
				//cout << "xsum = " << xsum << " i, j, len = " << i << " " << j << " " << len << "\n";
			}
			if(xsum == k)
			{
				maxn++;
				i += len - 1;
				continue;
			}
		}
		if(maxn > ans)
		{
//			bool flag = true;
//			for(int i = 1; i <= n; i++)
//			{
//				if(vis[i] && vis1[i])//ÖØºÏ 
//				{
//					flag = false;
//				}
//			}
//			if(flag)
//			{
//				ans = maxn;
//				for(int i = 1; i <= n; i++)
//				{
//					if(vis[i])
//					{
//						vis1[i] = vis[i];
//					}
//				}
//			}
//			memset(vis, 0, n);
			ans = maxn;
		}
	}
	cout << ans;
	return 0;
}
