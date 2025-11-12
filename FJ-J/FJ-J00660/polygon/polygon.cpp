#include <bits/stdc++.h>
using namespace std;
int n,l[5005],mod = 998244353,ans;
bool a[5005];
void bfs(int step)
{
	if(step > n)
	{
		int sum = 0,maxsum = 0,sl = 0;
		for(int i = 1;i <= n;i++)
		{
			if(a[i])
			{
				sum += l[i];
				maxsum = max(maxsum,l[i]);
				sl++;
			}
		}
		if(sl <= 2)
		{
			return;
		}
		else if(sum <= 2*maxsum)
		{
			return;
		}
		else
			ans++;
	}
	a[step] = 1;
	bfs(step+1);
	a[step] = 0;
}
bool cmp(int a,int b)
{
	return a<b;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> l[i];
	}
	sort(l,l+n,cmp);
	bfs(1);
	cout << ans % mod;
	return 0;
}
