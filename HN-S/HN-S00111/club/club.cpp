#include<bits/stdc++.h>
#define int long long

using namespace std;

inline int read()
{
	int x = 0 , f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		if(ch == '-')
			f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
const int N = 5e4 + 3;
int T;
struct node
{
	int fi , se , th;
	int big;
	bool f;
}a[N];
bool cmpf(node x , node y)
{
	if(x.big == x.fi && x.f == 1)
	{
		if(y.big == y.fi && y.f == 1)	return x.big > y.big;
		else	return 1;
	}
	return 0;
}
bool cmps(node x , node y)
{
	if(x.big == x.se && x.f == 1)
	{
		if(y.big == y.se && y.f == 1)	return x.big > y.big;
		else	return 1;
	}
	return 0;
}
bool cmpt(node x , node y)
{
	if(x.big == x.th && x.f == 1)
	{
		if(y.big == y.th && y.f == 1)	return x.big > y.big;
		else	return 1;
	}
	return 0;
}

signed main()
{
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	T = read();
	while(T --)
	{
		int n = read() , cnt1 = 0 , cnt2 = 0 , cnt3 = 0;
		if(n == 2)
		{
			int a1 = read() , b1 = read() , c1 = read() , a2 = read() , b2 = read() , c2 = read();
			int maxn = -0x3f3f3f3f;
			maxn = max(maxn , a1 + b2);
			maxn = max(maxn , a1 + c2);
			maxn = max(maxn , b1 + a2);
			maxn = max(maxn , b1 + c2);
			maxn = max(maxn , c1 + a2);
			maxn = max(maxn , c1 + b2);
			cout << maxn << '\n';
			continue;
		}
		memset(a , 0 , sizeof(a));
		for(int i = 1;i <= n; ++ i)
		{
			int x = read() , y = read() , z = read();
			a[i].fi = x , a[i].se = y , a[i].th = z;
			if(x >= y && y >= z || x >= z && z >= y)
			{
				a[i].big = x;
				cnt1 ++;
			}
			else	if(z >= x && x >= y || x <= y && y <= z)
			{
				a[i].big = z;
				cnt2 ++;
			}
			else
			{
				a[i].big = y;
				cnt3 ++;
			}
			a[i].f = 1;
//			cout << a[i].big << " " << a[i].fi << " " << a[i].se << " " << a[i].th << '\n';
//			cout << cnt1 << " " << cnt2 << " " << cnt3 << '\n';
		}
		int ans = 0;
		sort(a + 1 , a + n + 1 , cmpf);
		int kkk = n , o = min(kkk / 2 , cnt1);
		kkk -= o;
//		cout << kkk << " " << o << '\n';
		for(int i = 1;i <= o; ++ i)
		{
			ans += a[i].fi;
			a[i].f = 0;
//			cout << a[i].fi << " ";
		}
//		cout << '\n';
//		cout << ans << '\n';
		sort(a + 1 , a + n + 1 , cmps);
		o = min(kkk / 2 , cnt3);
		kkk -= o;
//		cout << kkk << " " << o << '\n';
		for(int i = 1;i <= o; ++ i)
		{
			ans += a[i].se;
			a[i].f = 0;
//			cout << a[i].se << " ";
		}
//		cout << '\n';
//		cout << ans << '\n';
		sort(a + 1 , a + n + 1 , cmpt);
		o = min(kkk / 2 , cnt2);
		kkk -= o;
//		cout << kkk << " " << o << '\n';
		for(int i = 1;i <= max(kkk , o); ++ i)
		{
			ans += a[i].th;
//			cout << a[i].th << " ";
		}
		cout << ans << '\n';
	}
	return 0;
}
/*
I don't want AFO.
*/
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
/*
Ren5Jie4Di4Ling5%
*/
