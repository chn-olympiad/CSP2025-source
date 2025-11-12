#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;
int n,ans;
struct cl
{
	int a,b,c;
}a[N];
struct clu
{
	int c,m,p;
	char mc;
}b[N * 3];
bool v[N];
int ja,jb,jc;
bool cmp(clu x,clu y)
{
	return x.c > y.c;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T --)
	{
		cin >> n;
		ans = 0;
		ja = jb = jc = 0;
		for(int i = 1;i <= n;i ++)
		{
			v[i] = 0;
		}
		for(int i = 1;i <= n;i ++)
		{
			cin >> a[i].a >> a[i].b >> a[i].c;
			b[i * 3 - 2].c = abs(a[i].a - a[i].b);
			b[i * 3 - 1].c = abs(a[i].a - a[i].c);
			b[i * 3].c = abs(a[i].b - a[i].c);
			if(a[i].a > a[i].b)
			{
				b[i * 3 - 2].m = a[i].a;
				b[i * 3 - 2].mc = 'a';
			}
			else
			{
				b[i * 3 - 2].m = a[i].b;
				b[i * 3 - 2].mc = 'b';
			}
			if(a[i].a > a[i].c)
			{
				b[i * 3 - 1].m = a[i].a;
				b[i * 3 - 1].mc = 'a';
			}
			else
			{
				b[i * 3 - 1].m = a[i].c;
				b[i * 3 - 1].mc = 'c';
			}
			if(a[i].b > a[i].c)
			{
				b[i * 3].m = a[i].b;
				b[i * 3].mc = 'b';
			}
			else
			{
				b[i * 3].m = a[i].c;
				b[i * 3].mc = 'c';
			}
			b[i * 3 - 2].p = b[i * 3 - 1].p = b[i * 3].p = i;
		}
		sort(b + 1,b + 1 + n * 3,cmp);
		for(int i = 1;i <= n * 3;i ++)
		{
			if(v[b[i].p])
			{
				continue;
			}
			if(b[i].mc == 'a')
			{
				if(ja >= (n >> 1))
				{
					continue;
				}
				ja ++;
			}
			else if(b[i].mc == 'b')
			{
				if(jb >= (n >> 1))
				{
					continue;
				}
				jb ++;
			}
			else
			{
				if(jc >= (n >> 1))
				{
					continue;
				}
				jc ++;
			}
			ans += b[i].m;
			v[b[i].p] = 1;
		}
		cout << ans << '\n';
	}
	return 0;
}
