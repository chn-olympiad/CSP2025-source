#include <bits/stdc++.h>
using namespace std;
struct note
{
	int y, e, s, m, c, x;	
}a[100005], b[100005], c[100005];
bool cmp1(note b1, note b2)
{
	return b1.y > b2.y;
}
bool cmp2(note b1, note b2)
{
	return b1.e > b2.e;
}
bool cmp3(note b1, note b2)
{
	return b1.s > b2.s;
}
int n, t, s, ar, br, cr;
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--)
	{
		s = 0;
		for (int i = 1; i <= n; i++)
		{
			a[i].y = b[i].y = c[i].y = 0;
			a[i].e = b[i].e = c[i].e = 0;
			a[i].s = b[i].s = c[i].s = 0;
			a[i].m = b[i].m = c[i].m = 0;
			a[i].c = b[i].c = c[i].c = 0;
			a[i].x = b[i].x = c[i].x = i;
		}
		ar = br = cr = 0;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i].y >> a[i].e >> a[i].s;
			if (a[i].y > a[i].e && a[i].y > a[i].s)
			{
				a[i].m = a[i].y;
				a[i].c = 1;
			}
			if (a[i].e > a[i].s && a[i].e > a[i].y)
			{
				a[i].m = a[i].e;
				a[i].c = 2;
			}
			if (a[i].s > a[i].y && a[i].s > a[i].e)
			{
				a[i].m = a[i].s;
				a[i].c = 3;
			}
			b[i].y = c[i].y = a[i].y;
			b[i].e = c[i].e = a[i].e;
			b[i].s = c[i].s = a[i].s;
			b[i].m = c[i].m = a[i].m;
			b[i].c = c[i].c = a[i].c;
		}
		sort(a + 1, a + n + 1, cmp1);
		sort(b + 1, b + n + 1, cmp2);
		sort(c + 1, c + n + 1, cmp3);
		if (b[1].e == c[1].s && b[1].e == 0)
		{
			for (int j = 1; j <= n / 2; j++)
			{
				s += a[j].y;
			}
			cout << s << endl;
			continue;
		}
		else if(c[1].s == 0)
		{
			for(int i = 1; i <= n; i++)
			{
				if (a[i].y > b[i].e)
				{
					if (a[i].y != 0 && ar < n / 2)
					{
						ar++;
						s += a[i].y;
						for(int j = 1; j <= n; j++)
						{
							if (b[j].x == a[i].x)
							{
								a[i].y = b[i].y = c[i].y = 0;
								a[i].e = b[i].e = c[i].e = 0;
								a[i].s = b[i].s = c[i].s = 0;
							}
						}
					} 
					if (b[i].y != 0 && br < n / 2)
					{
						br++;
						s += b[i].e;
						for(int j = 1; j <= n; j++)
						{
							if (a[j].x == b[i].x)
							{
								a[i].y = b[i].y = c[i].y = 0;
								a[i].e = b[i].e = c[i].e = 0;
								a[i].s = b[i].s = c[i].s = 0;
							}
						}
					 } 
				}
				if (a[i].y <= b[i].e)
				{
					if (b[i].y != 0 && br < n / 2)
					{
						br++;
						s += b[i].e;
					 } 
					if (a[i].y != 0 && ar < n / 2)
					{
						ar++;
						s += a[i].y;
					} 
				}
			}
			cout << s << endl;
			continue;  
		}
	}
} 
