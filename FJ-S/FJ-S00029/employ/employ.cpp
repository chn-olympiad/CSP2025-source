#include<bits/stdc++.h>
using namespace std;
int n, m, s, a[100000], b[100000], l, t = 1, h[100000];
char c;
int o(int x)
{
	if(!x)
		x = 1;
	if(x < 0)
		x = 0;
	return x;
}
void d(int f, int g)
{
	if(f == t)
	{
		if(g >= m)
		{
			int p = 1;
			for(int i = 1; i <= t; i++)
			{
				for(int k = a[i]; k >= a[i] - h[i] + 1; k--)
					p *= o(k);
				for(int k = n - a[i]; k >= n - a[i] - b[i] + h[i] + 1; k--)
					p *= o(k);
			}
			s += p;
		}
		return;
	}
	for(int i = 0; i <= b[f]; i++)
		h[f] = i, d(f + 1, g + i);
	return;
}
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> c;
		if(c - '0')
			a[t]++;
		else
			t++;
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> l;
		if(l > t)
			l = t;
		b[l]++;
	}
	d(0, 0), cout << s % 998244353;
	
	return 0;
} 
