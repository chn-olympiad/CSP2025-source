#include<bits/stdc++.h>
using namespace std;
int n, sumn = 0, cnt = 0, c = 0;
const int mod = 998244353;
int a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i];
	}
	for(int j = 3;j <= n;j++)
	{
		for(int k = 1;k <= n - j + 1;k++)
		{
			cout<<k<<" ";
			int T = j, b = k, maxn = -1;
			while(T--)
			{
				sumn += a[b];
				if(a[b] > maxn)
				{
					maxn = a[b];
				}
				b++;
			}
			if(sumn > (2 * maxn))
			{
				cnt += 1;
				cnt %= mod;
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}
