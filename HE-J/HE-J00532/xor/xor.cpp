#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 7;
int n,k,a[N],b[N];
struct stu
{
	int l,r;
}sum[N];
void solve()
{
	scanf("%d%d",&n,&k);
	for(int i = 1;i <= n;++i)
	{
		scanf("%d",a + i);
		b[i] = b[i - 1] ^ a[i];
	} 
	int res = 0;
	for(int i = 1;i <= n;++i)
	{
		int cnt = 0;
		for(int j = i;j <= n;++j)
		{
			cnt ^= a[j];
			if(cnt == k)
			{
				sum[++res].l = i,sum[res].r = j;
				break;
			}
		}
	}
	if(res == 0)
	{
		printf("0\n");
		return ;
	}
	int l = sum[1].l,r = sum[1].r,cnt = 1;
	for(int i = 2;i <= res;++i)
	{
		int ql = sum[i].l,qr = sum[i].r;
		
		if(qr <= r) r = qr,l = ql;
		else if(ql <= r && qr > r) continue;
		else if(ql > r) l = ql,r = qr,++cnt;
	}
	printf("%d\n",cnt);
}
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	solve();
}
