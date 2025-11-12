#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int t, n, ans;
int cnt1, cnt2, cnt3;
int dp[MAXN];
struct node
{
	int a, b, c;
};
node s[MAXN];
node t1[MAXN], t2[MAXN], t3[MAXN];
bool cmp1(node x, node y){return (x.a - max(x.b, x.c)) < (y.a - max(y.b, y.c));}
bool cmp2(node x, node y){return (x.b - max(x.a, x.c)) < (y.b - max(y.a, y.c));}
bool cmp3(node x, node y){return (x.c - max(x.a, x.b)) < (y.c - max(y.a, y.b));}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while(t --)
	{
		ans = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0;
		cin >> n;
		for(int i = 1; i <= n; i ++)
		{
			cin >> s[i].a >> s[i].b >> s[i].c;
			if(s[i].a >= s[i].b && s[i].a >= s[i].c)
			{
				cnt1 ++;
				t1[cnt1] = s[i];
				ans += s[i].a;
			}
			else if(s[i].b >= s[i].a && s[i].b >= s[i].c)
			{
				cnt2 ++;
				t2[cnt2] = s[i];
				ans += s[i].b;
			}
			else
			{
				cnt3 ++;
				t3[cnt3] = s[i];
				ans += s[i].c;
			}
		}
		if(cnt1 > n / 2)
		{
			sort(t1 + 1, t1 + cnt1 + 1, cmp1);
			for(int i = 1; i <= cnt1 - n / 2; i ++) ans -= (t1[i].a - max(t1[i].b, t1[i].c));
		}
		if(cnt2 > n / 2)
		{
			sort(t2 + 1, t2 + cnt2 + 1, cmp2);
			for(int i = 1; i <= cnt2 - n / 2; i ++) ans -= (t2[i].b - max(t2[i].a, t2[i].c));
		}
		if(cnt3 > n / 2)
		{
			sort(t3 + 1, t3 + cnt3 + 1, cmp3);
			for(int i = 1; i <= cnt3 - n / 2; i ++) ans -= (t3[i].c - max(t3[i].a, t3[i].b));
		}
		cout << ans << endl;
	}
	return 0;
}
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
//ÃÜÂë£ºRen5Jie4Di4Ling5%
