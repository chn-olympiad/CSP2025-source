#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Node{
	int l,r;
};

int n,k;
int a[500010];
int v[500010];
Node b[1000010]; int lb;

bool cmp(Node x,Node y)
{
	return x.r < y.r;
}

signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for (int i = 1;i <= n;i++)
	{
		scanf("%lld",&a[i]);
	}
	v[1] = a[1];
	for (int i = 2;i <= n;i++)
	{
		v[i] = a[i] ^ v[i - 1];
	}
	for (int i = 1;i <= n;i++)
	{
		for (int j = i;j <= n;j++)
		{
			int x = v[j] ^ v[i - 1];
			if (x == k)
			{
				Node tmp; tmp.l = i; tmp.r = j;
				b[++lb] = tmp;
			}
		}
	}
	sort(b + 1,b + lb + 1,cmp);
	int ans = 0,m = 0;
	for (int i = 1;i <= lb;i++)
	{
		if (b[i].l > m)
		{
			ans++;
			m = b[i].r;
		}
	}
	printf("%lld\n",ans);
	
	return 0;
}
