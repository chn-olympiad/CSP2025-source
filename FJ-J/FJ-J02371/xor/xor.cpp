#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
int dis[25] = {0, 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 
			   1024, 2048, 4096, 8192, 16384, 32768, 65536, 
			   131072, 262144, 524288, 1048576, 2097152};

int n, k, cnt = 1;
int a[N], s[N][N];
bool vis[N];

struct node
{
	int l, r, sz;
}b[N];

//窝要上迷惑行为大赏！！！ 
//时间复杂度炸掉了嘤嘤嘤ToT
//O(60 * n ^ 2)还有救吗ToT
//n==10 ^ 3的时候搏一把ToT
//六千万的复杂度我就等着吃'掉'吧ToT 
//T4感觉能打,待会再唱《雾鸦》
//猜一发19491001, 20251101, 5201314
//是不是还有You have no egg!!! 
//I LOVE CCF FOR EVER!!!

bool cmp(node ii, node jj)
{
	if(ii.sz != jj.sz)return ii.sz < jj.sz;
	else if(ii.l != jj.l)return ii.l < jj.l;
	return ii.r < jj.r;
}

int max1(int nw)
{
	if(nw == 0)return 0;
	for(int i = 22; i >= 0; i--)
	{
		if(dis[i] <= nw)return i;
	}
	return 0;
}

int xor1(int x, int y)
{
	int ans = 0;
	if(x == y)return 0;
	if(x == 0)return y;
	if(y == 0)return x;
	int xx[25] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, 
		yy[25] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	while(x > 0)
	{
		int u = max1(x);
		xx[u]++;
		x -= dis[u];
	}
	while(y > 0)
	{
		int u = max1(y);
		yy[u]++;
		y -= dis[u];
	}
	for(int i = 1; i <= 22; i++)
	{
		if(xx[i] != yy[i])ans += dis[i];
	}
	return ans;
}

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		s[i][i] = a[i];
		if(s[i][i] == k)
		{
			b[cnt].l = i;
			b[cnt].r = i;
			b[cnt].sz = 1;
			cnt++;
		}
		for(int j = 1; j < i; j++)
		{
			s[j][i] = xor1(s[j][i - 1], a[i]);
			if(s[j][i] == k)
			{
				b[cnt].l = j;
				b[cnt].r = i;
				b[cnt].sz = i - j + 1;
				cnt++;
			}
		}
	}
	
	sort(b + 1, b + cnt, cmp);
	
	int ans = 0;
	for(int i = 1; i < cnt; i++)
	{
		int f = 1;
		for(int j = b[i].l; j <= b[i].r; j++)
		{
			if(vis[j] == 1)f = 0;
		}
		if(f == 1)ans++;
		for(int j = b[i].l; j <= b[i].r; j++)vis[j] = 1;
	}
	
	cout << ans << endl;
	
	return 0;
}
