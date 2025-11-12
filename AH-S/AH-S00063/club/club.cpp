#include <bits/stdc++.h>
using namespace std;
#define int long long 
struct Node 
{
	int a,b,c,ma,cma;
} a[100005];
bool cmp1(Node a,Node b)
{
	return a.ma - a.cma > b.ma - b.cma;
}
/*
bool cmp2(Node a,Node b)
{
	return max({a.a,a.b}) > max({b.a,b.b});
}
bool cmp3(Node a,Node b)
{
	return max({a.a,a.c}) > max({b.a,b.c});
}
bool cmp4(Node a,Node b)
{
	return max({a.b,a.c}) > max({b.b,b.c});
}
*/
int calc(int a,int b,int c)
{
	return max(max(a,b),c);
}
signed main()
{
	freopen("club5.in","r",stdin);
	freopen("club.out","w",stdout);
	int T,n;
	cin >> T;
	while (T--)
	{
		cin >> n;
		for (int i = 1;i <= n;i++) a[i].a = a[i].b = a[i].c = a[i].ma = a[i].cma = 0;
		for (int i = 1;i <= n;i++) 
		{
			cin >> a[i].a >> a[i].b >> a[i].c;
			a[i].ma = calc(a[i].a,a[i].b,a[i].c);
			if (a[i].ma == a[i].a) a[i].cma = max(a[i].b,a[i].c);
			if (a[i].ma == a[i].b) a[i].cma = max(a[i].a,a[i].c);
			if (a[i].ma == a[i].c) a[i].cma = max(a[i].b,a[i].a);
		}
		sort(a + 1,a + n + 1,cmp1);
		int s1 = 0,s2 = 0,s3 = 0,ans = 0,j;
		for (int i = 1;i <= n;i++)
		{
			if (a[i].a == calc(a[i].a,a[i].b,a[i].c)) s1++,ans = ans + a[i].a;
			if (a[i].b == calc(a[i].a,a[i].b,a[i].c)) s2++,ans = ans + a[i].b;
			if (a[i].c == calc(a[i].a,a[i].b,a[i].c)) s3++,ans = ans + a[i].c;
			if (s1 == n / 2 || s2 == n / 2 || s3 == n / 2) 
			{
				j = i + 1;
				break;
			}
		}
		if (s1 + s2 + s3 == n)
		{
			cout << ans << '\n';
			continue;
		}
		else if (s1 == n / 2)
		{
			for (int i = j;i <= n;i++) ans = ans + a[i].cma;
		}
		else if (s2 == n / 2)
		{
			for (int i = j;i <= n;i++) ans = ans + a[i].cma;
		}
		else 
		{
			for (int i = j;i <= n;i++) ans = ans + a[i].cma;
		}
		cout << ans << '\n';
	}
	return 0;
}
