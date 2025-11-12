#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long 

const int N = 2e6 + 10,K = 15,M = 1e4 + 10,INF = 1e18;
int n,m,k,f[N],c[K],a[K][M],ans = INF;
bool p[N];

struct Bit
{
	int x,y,z;
}v[N],tot[N];

inline bool cmp(Bit x,Bit y)
{ return x.z < y.z; }

inline int find(int x)
{
	if (f[x] != x) f[x] = find(f[x]);
	return f[x];
}

inline int kruskal(int cnter,int cnt)
{
	int pos1 = 1,pos2 = 1,ans = 0;
	for(int i = 1;i <= n + k;i ++) f[i] = i;
	while (cnter > 1)
	{
		int x,y,z;
		if (pos2 <= cnt)
		{
			if (tot[pos2].z < v[pos1].z) x = tot[pos2].x,y = tot[pos2].y,z = tot[pos2].z,pos2 ++;
			else x = v[pos1].x,y = v[pos1].y,z = v[pos1].z,pos1 ++;
		}
		else x = v[pos1].x,y = v[pos1].y,z = v[pos1].z,pos1 ++;
		int fx = find(x),fy = find(y);
		if (fx == fy) continue;
		f[fx] = fy;
		cnter --;
		ans += z;
	}
	return ans;
}

inline int check()
{
	int cnter = n,cnt = 0;
	for(int i = 1;i <= k;i ++)
	{
		if (!p[i]) continue;
		cnter ++;
		for(int j = 1;j <= n;j ++) tot[++cnt] = {i + n,j,a[i][j]};
	}
	sort(tot + 1,tot + cnt + 1,cmp);
	return kruskal(cnter,cnt);
}

inline void dfs(int step,int sum)
{
	if (step > k)
	{
		ans = min(ans,sum + check());
		return ;
	}
	p[step] = 0;
	dfs(step + 1,sum);
	p[step] = 1;
	dfs(step + 1,sum + c[step]);
}

inline void read(int &x)
{
	x = 0;
	char ch;
	while ((ch = getchar()) && (ch >= '0' && ch <= '9'))
		x = (x << 1) + (x << 3) + (ch - '0');
}

signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= n;i ++) f[i] = i;
	for(int i = 1;i <= m;i ++)
	{
		int x,y,z;
//		read(x),read(y),read(z);
		cin >> x >> y >> z;
		v[i] = {x,y,z};
	}
	for(int i = 1;i <= k;i ++)
	{
//		read(c[i]);
		cin >> c[i];
		for(int j = 1;j <= n;j ++) 
			cin >> a[i][j];
	}
	sort(v + 1,v + m + 1,cmp);
	int cnter = 0,i = 0;
	while (cnter < n) 
	{
		i ++;
		int x = v[i].x,y = v[i].y,z = v[i].z;
		int fx = find(x),fy = find(y);
		if (fx == fy) continue;
		f[fx] = fy;
		cnter ++;
		tot[cnter] = v[i];
	}
	for(int i = 1;i <= n;i ++) v[i] = tot[i];
	dfs(1,0);
	cout << ans << endl;
	return 0;
}

/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/




