#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct node{
	int a,b,c,id;
	int id1,id2,maxn,second;
}a[N];
int cnt[4];
bool cmp(node x,node y)
{
	return x.maxn - x.second> y.maxn - y.second;
}
void init(int x)
{
	int t = max(max(a[x].a,a[x].b),a[x].c),tt = min(min(a[x].a,a[x].b),a[x].c);
	a[x].maxn = t,a[x].second = a[x].a + a[x].b + a[x].c - t - tt;
	if(a[x].a >= a[x].b && a[x].b >= a[x].c)
	{
		a[x].id1 = 1,a[x].id2 = 2;
	}
	else if(a[x].a >= a[x].c && a[x].c >= a[x].b)
	{
		a[x].id1 = 1,a[x].id2 = 3;
	}
	else if(a[x].b >= a[x].a && a[x].a >= a[x].c)
	{
		a[x].id1 = 2,a[x].id2 = 1;
	}
	else if(a[x].b >= a[x].c && a[x].c >= a[x].a)
	{
		a[x].id1 = 2,a[x].id2 = 3;
	}
	else if(a[x].c >= a[x].a && a[x].a >= a[x].b)
	{
		a[x].id1 = 3,a[x].id2 = 1;
	}
	else if(a[x].c >= a[x].b && a[x].b >= a[x].a)
	{
		a[x].id1 = 3,a[x].id2 = 2;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		cnt[1] = cnt[2] = cnt[3] = 0;
		for(int i = 1;i <= n;i++)
		{
			scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
			a[i].id = i;
			init(i);
		}
		int ans = 0;
		sort(a + 1,a + n + 1,cmp);
		for(int i = 1;i <= n;i++)
		{
		//	cout << a[i].id << " " << a[i].id1 << " " << a[i].maxn << " " << cnt[a[i].id1] << endl;
			if(cnt[a[i].id1] == n/2)
			{
				cnt[a[i].id2]++;
				ans += a[i].second;
			}
			else
			{
				cnt[a[i].id1]++;
				ans += a[i].maxn;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
