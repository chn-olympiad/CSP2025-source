#include <bits/stdc++.h>
using namespace std;
int n,a[5005],ans;
const int mod = 998244353;
bool cmp(int a,int b)
{
	return a > b;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i ++) cin >> a[i];
	sort(a + 1,a + n + 1,cmp);
	for(int i = 1;i <= n;i ++)
	{
		for(int j = 3;j < (1 << (n - i));j ++)
		{
			int sum = 0,cnt = 0;
			for(int k = 0;k < n - i;k ++)
			{
				if(j & (1 << k)) sum += a[i + k + 1],cnt ++;
			}
			if(sum > a[i] && cnt >= 2) ans = (ans + 1) % mod;
		}
	}
	cout << ans;
}
