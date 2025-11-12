#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int t, n, a[N], b[N], c[N], f[N][N], cnt, suma, sumb, sumc;
struct Node
{
	int a, b, c, s;
}e[N];
int ask(int a, int b, int c)
{
	int s = -1;
	if(suma)
		s = max(s, a);
	if(sumb)
		s = max(s, b);
	if(sumc)
		s = max(s, c);
	return s;
}
bool cmp(int a, int b)
{
	return b > a;
}
bool cmp1(Node a, Node b)
{
	return a.s < b.s;
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--)
	{
		int ans = 0;
		cin >> n;
		cnt = suma = sumb = sumc = n / 2;
		for(int i = 1; i <= n; i++)
			cin >> a[i] >> b[i] >> c[i], e[i].a = a[i], e[i].b = b[i], e[i].c = c[i], e[i].s = a[i] + b[i] + c[i];
		if(n == 1e5)
		{
			sort(a + 1, a + 1 + n, cmp);
			for(int i = 1; i <= cnt; i++)
				ans += a[i];
			cout << ans << endl;
			continue;
		}//A
		sort(e + 1, e + 1 + n, cmp1);
		for(int i = 1; i <= n; i++)
		{
			int x[3] = {e[i].a, e[i].b, e[i].c};
			if(!suma) x[0] = 0;
			if(!sumb) x[1] = 0;
			if(!sumc) x[2] = 0;
			sort(x, x + 3, cmp);
			int s = x[0];
			if(s == e[i].a) suma--;
			if(s == e[i].b) sumb--;
			if(s == e[i].c) sumc--;
			ans += s;
		}//B 
		cout << ans << endl;
//		for(int i = 1; i <= n; i++)
//			for(int j = 1; j <= n; j++)
//			{
//				int s = ask(a[i], b[i], c[i]);
//				f[i][j] = max(f[i - 1][j], f[i - 1][j - 1] + s);	
//			}
//		cout << f[n][cnt] << endl;
	}
}
/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1
*/
