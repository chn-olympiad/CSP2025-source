#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
int n,k,a[maxn],vis[1500010];
int mp[1010][1010],_60[1010];
bool dA = 1,dB = 1,dC = 1;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i]; _60[i] = a[i];
		mp[i][i] = a[i];
		if(a[i] != 1) dA = 0;
		if(!(0 <= a[i] && a[i] <= 1)) dB = 0;
		if(!(0 <= a[i] && a[i] <= 255)) dC = 0;
	}
	
	if(dA)
	{
		cout << n/2;
		return 0;
	}
	if(dB)
	{
		if(k == 1)
		{
			int cnt1 = 0;
			for(int i = 1;i <= n;i++)
				cnt1 += a[i];
			cout << cnt1;
			return 0;
		}
		else
		{
			int cnt2 = 0,now2 = 0;
			for(int i = 1;i <= n;i++)
			{
				if(a[i] == 0) cnt2++,now2 = 0;
				if(a[i] == 1)
				{
					now2++;
					if(now2 == 2) cnt2++,now2 = 0;
				}
			}
			cout << cnt2;
			return 0;
		}
	}
	if(n <= 1000)
	{
		int ans3 = 0;
		for(int i = 2;i <= n;i++)
		{
			for(int j = 1;j < i;j++)
			{
				_60[j] = _60[j] ^ a[i];
				mp[j][i] = _60[j];
			}
			for(int j = 1;j <= i;j++)
				mp[j][i] = _60[j];
		}
		int lst = 1;
		for(int i = 1;i <= n;i++)
		{
			for(int j = lst;j <= i;j++)
				if(mp[j][i] == k)
				{
					ans3++;
					lst = i+1;
					break;
				}
		}
		cout << ans3;
		return 0;
	}
	return 0;
}

