#include <bits/stdc++.h>
using namespace std;
long long n, s, cnt, maxn, a[5555];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int z=i;z<=j;z++)
			{
				maxn = max(a[z], maxn);
				s += a[z];
			}
			if(s>maxn*2)
				cnt++;
			s=0;
			maxn = 0;
		}
	}
	cout << cnt;
	return 0;
}

