#include<bits/stdc++.h>
using namespace std;
const int N = 200005;

int n, q;
string s1[N], s2[N], s3[N], s4[N];
string a, b, c, d, l, r, u, v;

bool blg(string xx, string yy)
{
	if(xx.size() >= yy.size() && xx != yy)return 0;
	int aa = xx.size(), bb = yy.size();
	int x = yy.size();
	bool f = 0;
	u = ' ';
	v = ' ';
	for(int i = 0; i < x; i++)
	{
		if(f)
		{
			u += xx[i];
			v += yy[i];
		}
		else if(xx[i] != yy[i])
		{
			u = xx[i];
			v = yy[i];
			f = 1;
		}
	}
	x = v.size();
	f = 0;
	for(int i = x - 1; i >= 0; i--)
	{
		if(f)
		{
			xx = u[i] + xx;
			yy = v[i] + yy;
		}
		else if(u[i] != v[i])
		{
			xx = u[i];
			yy = v[i];
			f = 1;
		}
	}
	if(v.size() - u.size() == bb - aa)return 1;
	return 0;
}

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> q;
	for(int t = 1; t <= n; t++)
	{
		cin >> s1[t] >> s2[t];
		if(s1[t] == s2[t])continue;
		int x = s1[t].size();
		bool f = 0;
		a = ' ';
		b = ' ';
		for(int i = 0; i < x; i++)
		{
			if(f)
			{
				a += s1[t][i];
				b += s2[t][i];
			}
			else if(s1[t][i] != s2[t][i])
			{
				a = s1[t][i];
				b = s2[t][i];
				f = 1;
			}
		}
		x = a.size();
		f = 0;
		for(int i = x - 1; i >= 0; i--)
		{
			if(f)
			{
				s3[t] = a[i] + s3[t];
				s4[t] = b[i] + s4[t];
			}
			else if(a[i] != b[i])
			{
				s3[t] = a[i];
				s4[t] = b[i];
				f = 1;
			}
		}
	}
	
	
	
	for(int t = 1; t <= q; t++)
	{
		cin >> a >> b;
		if(a == b)
		{
			cout << 0 << endl;
			continue;
		}
		int x = a.size();
		bool f = 0;
		c = ' ';
		d = ' ';
		for(int i = 0; i < x; i++)
		{
			if(f)
			{
				c += a[i];
				d += b[i];
			}
			else if(a[i] != b[i])
			{
				f = 1;
				c = a[i];
				d = b[i];
			}
		}
		x = c.size();
		f = 0;
		l = ' ';
		r = ' ';
		for(int i = x - 1; i >= 0; i--)
		{
			if(f)
			{
				l = c[i] + l;
				r = d[i] + r;
			}
			else if(c[i] != d[i])
			{
				l = c[i];
				r = d[i];
				f = 1;
			}
		}
		int cnt = 0;
		for(int i = 1; i <= n; i++)
		{
			if(l == s3[i] && r == s4[i] && blg(l, s3[i]) && blg(r, s4[i]))cnt++;
		}
		printf("%d\n", cnt);
	}
	
	return 0;
} 
