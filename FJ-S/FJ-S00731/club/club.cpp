#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int t, n;
long long num[5], ans;
struct Club
{
	long long a, b, c, m, v;
}club[N];
bool cmp1(Club x,Club y)
{
	if (x.v == 1 && y.v == 1)
	{
		return min(x.a-x.b,x.a-x.c) < min(y.a-y.b,y.a-y.c);
	}
	if (y.v == 1)
	{
		return false;
	}
	return true;
}
bool cmp2(Club x,Club y)
{
	if (x.v == 2 && y.v == 2)
	{
		return min(x.b-x.a,x.b-x.c) < min(y.b-y.a,y.b-y.c);
	}
	if (y.v == 2)
	{
		return false;
	}
	return true;
}
bool cmp3(Club x,Club y)
{
	if (x.v == 3 && y.v == 3)
	{
		return min(x.c-x.b,x.c-x.a) < min(y.c-y.b,y.c-y.a);
	}
	if (y.v == 3)
	{
		return false;
	}
	return true;
}
int main()
{
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	cin >> t;
	while (t--)
	{
		cin >> n;
		num[1] = num[2] = num[3] = ans = 0;
		for (int i = 1;i <= n;i++)
		{
			cin >> club[i].a >> club[i].b >> club[i].c;
			club[i].m = max(club[i].a,max(club[i].b,club[i].c));
			if (club[i].m == club[i].a)
			{
				club[i].v = 1;
				num[1]++;
			}
			else if (club[i].m == club[i].b)
			{
				club[i].v = 2;
				num[2]++;
			}
			else if (club[i].m == club[i].c)
			{
				club[i].v = 3;
				num[3]++;
			}
		}
		if (num[1] > n/2)
		{
			sort(club+1,club+n+1,cmp1);
			for (int i = 1;i <= num[1] - n/2;i++)
			{
				if (club[i].a-club[i].b < club[i].a-club[i].c)
				{
					club[i].v = 2;
				}
				else
				{
					club[i].v = 3;
				}
			}
		}
		else if (num[2] > n/2)
		{
			sort(club+1,club+n+1,cmp2);
			for (int i = 1;i <= num[2] - n/2;i++)
			{
				if (club[i].b-club[i].a < club[i].b-club[i].c)
				{
					club[i].v = 1;
				}
				else
				{
					club[i].v = 3;
				}
			}
		}
		else if (num[3] > n/2)
		{
			sort(club+1,club+n+1,cmp3);
			for (int i = 1;i <= num[3] - n/2;i++)
			{
				if (club[i].c-club[i].a < club[i].c-club[i].b)
				{
					club[i].v = 1;
				}
				else
				{
					club[i].v = 2;
				}
			}
		}
		for (int i = 1;i <= n;i++)
		{
			if (club[i].v == 1)
			{
				ans += club[i].a;
			}
			if (club[i].v == 2)
			{
				ans += club[i].b;
			}
			if (club[i].v == 3)
			{
				ans += club[i].c;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
