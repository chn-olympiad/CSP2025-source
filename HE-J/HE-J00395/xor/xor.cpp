#include <bits/stdc++.h>
using namespace std;
int n,a[500005],k,m,ans;
struct node
{
	int l,r;
}b[500005];
bool cmp(node a,node b)
{
	return a.r < b.r;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 1;i <= n;i ++) cin >> a[i];
	for(int i = 1;i <= n;i ++)
	{
		int t = 0;
		for(int j = i;j <= n;j ++)
		{
			t ^= a[j];
			if(t == k) b[++m] = (node){i,j};
		}
	}
	sort(b + 1,b + m + 1,cmp);
	int now = 1;
	for(int i = 1;i <= m;i ++)
	{
		if(b[i].l <= now)
		{
			ans ++;
			now = b[i].r;
		}
	}
	cout << ans;
}
