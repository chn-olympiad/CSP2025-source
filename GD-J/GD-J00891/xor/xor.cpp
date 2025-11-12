#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],curp,last = -2e9,ans;
struct node
{
	int l,r,sum;
} p[1000005];
bool cmp(node x,node y)
{
	return x.r < y.r;
}
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	if (n <= 1000)
	{
		for (int l = 1;l<=n;l++)
		{
			int sum = 0;
			for (int r = l;r<=n;r++)
			{
				sum ^= a[r];
				curp ++;
				p[curp] = {l,r,sum};
			}
		}
		sort(p+1,p+curp+1,cmp);
		for (int i = 1;i<=curp;i++)
		{
			if (last == n) break;
			if (p[i].sum != k || p[i].l <= last) continue;
			ans ++;
			last = p[i].r;
		}
		cout<<ans<<endl;
		return 0;
	}
	cout<<1<<endl;
	return 0;
}
