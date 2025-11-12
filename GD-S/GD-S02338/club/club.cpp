#include <bits/stdc++.h>
using namespace std;
int n;
int t;
long long ans;
struct node
{
	int a,b,c;
}p[100005];
bool cmp(node x,node y)
{
	return max(max(x.a,x.b),x.c) >= max(max(y.a,y.b),y.c);
}
int cnt[4],f[4],l[100005],tag[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out", "w",stdout);
	cin >> t;
	while(t--)
	{
		cin >> n;
		ans = 0;
		memset(cnt,0,sizeof(cnt));
		memset(f,0,sizeof(f));
		memset(p,0,sizeof(p));
		memset(l,0,sizeof(l));
		memset(tag,0,sizeof(tag));
		for (int i = 1;i <= n;i ++)
		{
			cin >> p[i].a >> p[i].b >> p[i].c;	
		}
		sort(p+1,p+n+1,cmp);
		for (int i = 1;i <= n;i ++)
		{
			l[i] = max(max(p[i].a,p[i].b),p[i].c);
			if (l[i] == p[i].a) l[i] -= max(p[i].b,p[i].c);
			else if (l[i] == p[i].b)  l[i] -= max(p[i].a,p[i].c);
			else if (l[i] == p[i].c) l[i] -= max(p[i].a,p[i].b);
		}
		for (int i = 1;i <= n;i ++)
		{
			int tmp = max(max(p[i].a,p[i].b),p[i].c);
			int r = 0;
			if (tmp == p[i].a && f[1] != 1)  r = 1;
			else if (tmp == p[i].b && f[2] != 1)  r = 2;
			else if (tmp == p[i].c && f[3] != 1) r = 3;
			else if (tmp == p[i].a && f[1] == 1) 
			{
				int minn = 0x7fffffff;
				int idn = 0;
				for (int j = 1;j < i;j ++)
				{
					if (max(max(p[j].a,p[j].b),p[j].c) == p[j].a && tag[j] == 0)
					{
						if (minn > l[j]) idn = j;
						minn=min(minn,l[j]);
					}
					else continue;
				}
				if (l[i] > minn) {
					tag[idn] = 1;
					ans = ans - p[idn].a + p[i].a + max(p[idn].b,p[idn].c);
					continue;
				}
				else if (max(p[i].b,p[i].c) == p[i].b) r = 2;
				else r = 3;
			}
			else if (tmp == p[i].b && f[2] == 1) 
			{
				int minn = 0x7fffffff;
				int idn = 0;
				for (int j = 1;j < i;j ++)
				{
					if (max(max(p[j].a,p[j].b),p[j].c) == p[j].b && tag[j] == 0)
					{
						if (minn > l[j]) idn = j;
						minn=min(minn,l[j]);
					}
					else continue;
				}
				if (l[i] > minn) 
				{
					tag[idn] = 1;
					ans = ans - p[idn].b + p[i].b + max(p[idn].a,p[idn].c);
					continue;
				}
				if (max(p[i].a,p[i].c) == p[i].a) r = 1;
				else r = 3;
			}
			else if (tmp == p[i].c && f[3] == 1) 
			{
				int minn = 0x7fffffff;
				int idn = 0;
				for (int j = 1;j < i;j ++)
				{
					if (max(max(p[j].a,p[j].b),p[j].c) == p[j].c && tag[j] == 0)
					{
						if (minn > l[j]) idn = j;
						minn=min(minn,l[j]);
					}
					else continue;
				}
				if (l[i] > minn) {
					tag[idn] = 1;
					ans = ans - p[idn].c + p[i].c + max(p[idn].a,p[idn].b);
					continue;
				}
				else if (max(p[i].b,p[i].a) == p[i].b) r = 2;
				else r = 1;
			}
			if (r == 1) ans += p[i].a;
			else if (r == 2) ans += p[i].b;
			else if (r == 3) ans += p[i].c;
			cnt[r] ++;
			if (cnt[r] == n/2)
			{
				f[r] = 1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}

