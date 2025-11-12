#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

struct Mem
{
	int a, b, c;
} m[N];

bool cmp1(Mem p, Mem q)
{
	if(p.a != q.a) return p.a > q.a;
	return max(p.b, p.c) > max(q.b, q.c);
}

bool cmp2(Mem p, Mem q)
{
	return p.a > q.a;
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		if(n == 2)
		{
			int x1, y1, z1, x2, y2, z2;
			cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
			cout << max(max(x1+y2, z1+y2), max(max(x1+z2, y1+x2), max(y1+z2, z1+x2))) << endl;
			continue;
		}
		bool f = true;
		for(int i = 1; i <= n; i++)
		{
			cin >> m[i].a >> m[i].b >> m[i].c;
			if(m[i].b != 0 || m[i].c != 0) f = false;
		}
		if(f)
		{
			sort(m+1, m+n+1, cmp2);
			int jg = 0;
			for(int i = 1; i <= n/2; i++) jg += m[i].a;
			cout << jg << endl;
			continue;
		}
		
		sort(m+1, m+n+1, cmp1);
		int ans =  0, Ca = 0, Cb = 0, Cc = 0;
		for(int i = 1; i <= n; i++)
		{
			int x = m[i].a, y = m[i].b, z = m[i].c, mx = max(x, max(y, z));
			if(mx==x && Ca < n/2) ans += x, Ca++;
			else if(mx==y && Cb < n/2) ans += y, Cb++;
			else ans += z, Cc++;
		}
		cout << ans << endl;
	}
	return 0;
}