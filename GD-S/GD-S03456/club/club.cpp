#include <bits/stdc++.h>
using namespace std;
int T, n;
long long t[100005][5], cida[100005];
struct node{
	long long num, val;
}a[100005], b[100005], c[100005];
int tag[100005];
bool cmp(node x, node y)
{
	return (x.val-cida[x.num]) > (y.val-cida[y.num]);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		long long cnta = 0, cntb = 0, cntc = 0, ans = 0;
		scanf("%d",&n);
		for(int i = 1; i <= n; i++)
		{
			tag[i] = cida[i] = a[i].val = a[i].num = b[i].val = b[i].num = c[i].val = c[i].num =0;
		}
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= 3; j++)
			{
				scanf("%lld",&t[i][j]);
			}
			if(t[i][1] > t[i][2] && t[i][1] > t[i][3]) cnta++, a[cnta].val = t[i][1], a[cnta].num = i;
			else if(t[i][2] > t[i][1] && t[i][2] > t[i][3]) cntb++, b[cntb].val = t[i][2], b[cntb].num = i;
			else if(t[i][3] > t[i][1] && t[i][3] > t[i][2]) cntc++, c[cntc].val = t[i][3], c[cntc].num = i;
			if(t[i][1] >= min(t[i][2],t[i][3]) && t[i][1] <= max(t[i][2],t[i][3])) cida[i] = t[i][1];
			else if(t[i][2] >= min(t[i][1],t[i][3]) && t[i][2] <= max(t[i][1],t[i][3])) cida[i] = t[i][2];
			else cida[i] = t[i][3];
		}
			
		if(cnta<=n/2&&cntb<=n/2&&cntc<=n/2)
		{
			for(int i = 1; i <= n; i++)
			{
				ans += max(t[i][1],max(t[i][2],t[i][3]));
			}
			printf("%lld\n",ans);
			continue;
		}
		sort(a+1,a+1+cnta,cmp);
		sort(b+1,b+1+cntb,cmp);
		sort(c+1,c+1+cntc,cmp);
		if(cnta > n/2)
		{
			for(int i = 1; i <= n/2; i++) ans += a[i].val, tag[a[i].num]++;
			for(int i = 1; i <= n; i++) if(!tag[i]) ans += max(t[i][2],t[i][3]);
		}else if(cntb > n/2)
		{
			for(int i = 1; i <= n/2; i++) ans += b[i].val, tag[b[i].num]++;
			for(int i = 1; i <= n; i++) if(!tag[i]) ans += max(t[i][1],t[i][3]);
		}else{
			for(int i = 1; i <= n/2; i++) ans += c[i].val, tag[c[i].num]++;
			for(int i = 1; i <= n; i++) if(!tag[i]) ans += max(t[i][1],t[i][2]);
		}
		printf("%lld\n",ans);
	}
}
