#include <bits/stdc++.h>
using namespace std;
int n,a[10010];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	int ans = 0;
	for (int i = 1;i <= n - 2;i++)
	{
		int cnt = 0,maxn = a[i],cut = 1;
		cnt += a[i];
		for (int j = i+1;j <= n;j++)
		{
			for (int k = j;k <= n;k++)
			{
				if (a[k] > maxn) maxn = a[k];
				cnt+=a[k];
				cut++;
				if (cnt > 2 * maxn && cut >= 3) 
				{
					ans++;
				}
			}
			cnt = a[i],cut = 1,maxn = a[i];
		}
	}
	cout << ans; 
    return 0;
}
