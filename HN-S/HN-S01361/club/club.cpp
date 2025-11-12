#include <bits/stdc++.h>

using namespace std;

struct Node
{
	int a, b, c;
	char f;
};

const int N = 1e5 + 5;
int n, t;

bool cmp1(Node x, Node y)
{
	if (x.f == y.f && y.f == 'a')
	{
		return x.a - max(x.b, x.c) < y.a - max(y.b, y.c);
	}
	else
	{
		if (x.f == 'a')
		{
			if (x.a > y.a)
			{
				return x.a > y.a;
			}
			else
			{
				return x.a < y.a;
			}
		}
		else
		{
			if (x.a > y.a)
			{
				return x.a < y.a;
			}
			else
			{
				return x.a > y.a;
			}
		}
	}
}
bool cmp2(Node x, Node y)
{
	if (x.f == y.f && y.f == 'b')
	{
		return x.b - max(x.c, x.a) < y.b - max(y.c, y.a);
	}
	else
	{
		if (x.f == 'b')
		{
			if (x.b > y.b)
			{
				return x.b > y.b;
			}
			else
			{
				return x.b < y.b;
			}
		}
		else
		{
			if (x.b > y.b)
			{
				return x.b < y.b;
			}
			else
			{
				return x.b > y.b;
			}
		}
	}
}
bool cmp3(Node x, Node y)
{
	if (x.f == y.f && y.f == 'c')
	{
		return x.c - max(x.b, x.a) < y.c - max(y.b, y.a);
	}
	else
	{
		if (x.f == 'c')
		{
			if (x.c > y.c)
			{
				return x.c > y.c;
			}
			else
			{
				return x.c < y.c;
			}
		}
		else
		{
			if (x.c > y.c)
			{
				return x.c < y.c;
			}
			else
			{
				return x.c > y.c;
			}
		}
	}
}

int main() 
{
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	cin >> t;
	while (t --)
	{
		cin >> n;
		int pp = n/2, ap = 0, bp = 0, cp = 0, sa = 0, sb = 0, sc = 0;
		Node p[N];
		for (int i = 1;i <= n;i ++)
		{
			cin >> p[i].a >> p[i].b >> p[i].c;
			if (p[i].a >= p[i].b && p[i].a >= p[i].c)
			{
				ap ++;
				sa += p[i].a;
				p[i].f = 'a';
			}
			else if (p[i].b >= p[i].a && p[i].b >= p[i].c)
			{
				bp ++;
				sb += p[i].b;
				p[i].f = 'b';
			}
			else if (p[i].c >= p[i].b && p[i].a <= p[i].c)
			{
				cp ++;
				sc += p[i].c;
				p[i].f = 'c';
			}
		}
		while(ap > pp)
		{
			sort (p + 1, p + n + 1, cmp1);
			ap --;
			sa -= p[1].a;
			p[1].a = 0;
			if (p[1].b > p[1].c)
			{
				sb += p[1].b;
				p[1].f = 'b';
				bp ++; 
			}
			else
			{
				sc += p[1].c;
				p[1].f = 'c';
				cp ++;
			}	
		}
		while(bp > pp)
		{
			sort (p + 1, p + n + 1, cmp2);
			bp --;
			sb -= p[1].b;
			p[1].b = 0;
			if (p[1].a > p[1].c)
			{
				sa += p[1].a;
				p[1].f = 'a';
				ap ++; 
			}
			else
			{
				sc += p[1].c;
				p[1].f = 'c';
				cp ++;
			}
		}
		while(cp > pp)
		{
			sort (p + 1, p + n + 1, cmp3);
			cp --;
			sc -= p[1].c;
			p[1].c = 0;
			if (p[1].a > p[1].b)
			{
				sa += p[1].a;
				p[1].f = 'a';
				ap ++; 
			}
			else
			{
				sb += p[1].b;
				p[1].f = 'b';
				bp ++;
			}
		}
		cout << sa + sb + sc << endl;
	}
	return 0;
}
