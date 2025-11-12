#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int n,k,ans;
int a[N],b[N];
struct xo
{
	int l,r;
}c[N];
int cnt;
int f[N];
bool cmp(xo x,xo y)
{
	if(x.r == y.r)
	{
		return x.l > y.l;
	}
	return x.r < y.r;
}
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> k;
	for(int i = 1;i <= n;i ++)
	{
		cin >> a[i];
		b[i] = b[i - 1] ^ a[i];
	}
	for(int i = 1;i <= n;i ++)
	{
		for(int j = i;j <= n;j ++)
		{
			if((b[j] ^ b[i - 1]) == k)
			{
				c[++ cnt].l = i;
				c[cnt].r = j;
			}
		}
	}
	sort(c + 1,c + 1 + cnt,cmp);
	f[1] = 1;
	for(int i = 1;i <= cnt;i ++)
	{
		for(int j = 1;j < i;j ++)
		{
			if(c[i].l > c[j].r)
			{
				f[i] = max(f[i],f[j] + 1);
			}
			else
			{
				f[i] = max(f[i],f[j]);
			}
		}
	}
	cout << f[cnt] << '\n';
	return 0;
}
