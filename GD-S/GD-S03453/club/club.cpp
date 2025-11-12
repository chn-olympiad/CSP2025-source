#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <cstring>
using namespace std;
struct aaa
{
	int a,b,c;
}p[100005],a[100005],b[100005],c[100005];
int t,n,c1,c2,c3,ans,v;
bool cmp1(aaa x,aaa y)
{
	return min(x.a - x.b,x.a - x.c) > min(y.a - y.b,y.a - y.c);
}
bool cmp2(aaa x,aaa y)
{
	return min(x.b - x.a,x.b - x.c) > min(y.b - y.a,y.b - y.c);
}
bool cmp3(aaa x,aaa y)
{
	return min(x.c - x.b,x.c - x.a) > min(y.c - y.b,y.c - y.a);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--)
	{
		c1 = c2 = c3 = 0;
//		memset(a,0,sizeof(a));
//		memset(b,0,sizeof(b));
//		memset(b,0,sizeof(c));
		cin >> n;
		for(int i = 1;i <= n;i++)
		{
			scanf("%d%d%d",&p[i].a,&p[i].b,&p[i].c);
			if(p[i].a > p[i].b && p[i].a > p[i].c) a[++c1] = p[i];
			else if(p[i].b > p[i].a && p[i].b > p[i].c) b[++c2] = p[i];
			else if(p[i].c > p[i].a && p[i].c > p[i].b) c[++c3] = p[i];
			else a[++c1] = p[i];
		}
		while(1)
		{
			bool q = 1;
			if(c1 > (n/2))
			{
				q = 0;
				sort(a + 1,a + c1 + 1,cmp1);
				while(c1 > (n/2))
				{
					if(a[c1].b > a[c1].c) b[++c2] = a[c1--];
					else c[++c3] = a[c1--];
				}
			}
			if(c2 > (n/2))
			{
				q = 0;
				sort(b + 1,b + c2 + 1,cmp2);
				while(c2 > (n/2))
				{
					if(b[c2].a > b[c2].c) a[++c1] = b[c2--];
					else c[++c3] = b[c2--];
				}
			}
			if(c3 > (n/2))
			{
				q = 0;
				sort(c + 1,c + c3 + 1,cmp3);
				while(c3 > (n/2))
				{
					if(c[c3].a > c[c3].b) a[++c1] = c[c3--];
					else b[++c2] = c[c3--];
				}
			}
			if(q) break;
		}
		sort(a + 1,a + c1 + 1,cmp1);
		sort(b + 1,b + c2 + 1,cmp2);
		sort(c + 1,c + c3 + 1,cmp3);
		while(1)
		{
			if(!((a[c1].a >= a[c1].b || c2 == (n/2)) && (a[c1].a >= a[c1].c || c3 == (n/2))))
			{
				if(a[c1].b > a[c1].c) b[++c2] = a[c1--];
				else c[++c3] = a[c1--];
			}else break;
		}
		while(1)
		{
			if(!((b[c2].b >= b[c2].a || c1 == (n/2)) && (b[c2].b >= b[c2].c || c3 == (n/2))))
			{
				if(b[c2].a > b[c2].c) a[++c1] = b[c2--];
				else c[++c3] = b[c2--];
			}else break;
		}
		while(1)
		{
			if(!((c[c3].c >= c[c3].a || c1 == (n/2)) && (c[c3].c >= c[c3].b || c2 == (n/2))))
			{
				if(c[c3].a > a[c1].b) a[++c1] = c[c3--];
				else b[++c2] = c[c3--];
			}else break;
		}
		ans = 0;
		for(int i = 1;i <= c1;i++) ans += a[i].a;
		for(int i = 1;i <= c2;i++) ans += b[i].b;
		for(int i = 1;i <= c3;i++) ans += c[i].c;
		cout << ans << endl;
		//cout << c1 << " " << c2 << " " << c3 << endl;
	}
	return 0;
}
