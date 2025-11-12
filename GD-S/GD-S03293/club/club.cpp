#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
struct node
{
	int a,b,c;
}p[100005];
int n;
bool cmp1(node x,node y)
{
	return x.a > y.a;
}
bool cmp2(node x,node y)
{
	return x.a - x.b > y.a - y.b;
}
void da()
{
	int ans = 0;
	sort(p + 1,p + n + 1,cmp1);
	for(int i = 1;i <= n / 2;i++) ans += p[i].a;
	cout << ans << endl;
}
void db()
{
	int ans = 0;
	sort(p + 1,p + n + 1,cmp2);
	for(int i = 1;i <= n / 2;i++) ans += p[i].a;
	for(int i = n / 2 + 1;i <= n;i++) ans += p[i].b;
	cout << ans << endl;
}
int ans;
bool v[100005];
void dfs(int st,int a,int b,int c,int sum)
{
	if(a + b + c > n) return;
	if(a > n / 2 || b > n / 2 || c > n / 2) return;
	if(st > n)
	{
		ans = max(ans,sum);
		return;
	}
	dfs(st + 1,a + 1,b,c,sum + p[st].a);
	dfs(st + 1,a,b + 1,c,sum + p[st].b);
	dfs(st + 1,a,b,c + 1,sum + p[st].c);
}
void dc()
{
	ans = 0;
	dfs(1,0,0,0,0);
	cout << ans << endl;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--)
	{
		int ans = 0;
		cin >> n;
		bool fa = true,fb = true;
		for(int i = 1;i <= n;i++)
		{
			cin >> p[i].a >> p[i].b >> p[i].c;
			if(p[i].c != 0) fa = fb = false;
			if(p[i].b != 0) fa = false;
		}
		if(fa)
		{
			da();
		}
		else if(fb)
		{
			db();
		}
		else
		{
			dc();
		}
	}
	return 0;
} 
