#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

typedef long long LL;
bool vis[15],fl[10005];
int f[10005],n,m,k;
LL mn1[15][10005],mn2[15][10005],c[15],ps[15][10005],d;
vector <int> v[10005],v2[10005];
struct node
{
	int u,v;
	LL w;
}a[1000005];
LL q[15][10005];
struct sc
{
    int id;
    LL x;
}p[15][10005];
bool cmp(node x,node y){
	return x.w < y.w;
}
bool cmp2(sc x,sc y){
	return x.x < y.x;
}
int find(int x)
{
	if (f[x] == x) return x;
	return f[x] = find(f[x]);
}
void merge(int x,int y){
	f[find(x)] = find(y);
}
void solve1(int x,int fa)
{
    for (int j = 1;j <= k;j++)
        mn2[j][x] = q[j][x];
    LL maxn = 0,reg[11] = {1,1,1,1,1,1,1,1,1,1,1};
	for (int i = 0;i < v[x].size();i++)
    {
    	int y = v[x][i];
    	if (y == fa) continue;
    	solve1(y,x);
    	for (int j = 1;j <= k;j++)
    	{
    		mn2[j][x] = min(mn2[j][x],mn2[j][y]);
    		reg[j] = max(reg[j],ps[j][y]);
    	}
    }
    fl[x] = 1;
    for (int i = 1;i <= n;i++)
    {
	    int cur = reg[i];
	    while (fl[p[i][cur].id]) cur++;
	    if (cur > n) continue;
	    mn1[i][x] = p[i][cur].x,ps[i][x] = cur;
	}
    return; 
}
LL reg,ans,ccc;
void solve2(int x,int fa)
{
    for (int i = 0;i < v[x].size();i++)
    {
    	int y = v[x][i];
    	if (y==fa) continue;
    	LL minn = v2[x][i];
    	for (int j = 1;j <= k;j++)
    		if (vis[j])
    			minn = min(minn,q[j][x]+mn2[j][y]);
    	reg += min(minn,1ll*v2[x][i]);
    	solve2(y,x);
    }
}
void dfs(int st,LL sum)
{
    if (st > k)
    {
    	ccc++;
        reg = 0;
        solve2(1,0);
        ans = min(ans,reg+sum);
    	return;
    }
    vis[st] = 1;
    dfs(st+1,sum+c[st]);
    vis[st] = 0;
    dfs(st+1,sum);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(mn1,0x7f,sizeof(mn1));
	memset(mn2,0x7f,sizeof(mn2));
    scanf("%d%d%d",&n,&m,&k);
    for (int i = 1;i <= n;i++)
    	f[i] = i;
    for (int i = 1;i <= m;i++)
        scanf("%d%d%lld",&a[i].u,&a[i].v,&a[i].w);
    for (int i = 1;i <= k;i++)
    {
    	scanf("%lld",&c[i]);
    	for (int j = 1;j <= n;j++)
    		scanf("%lld",&p[i][j].x),p[i][j].id = j,q[i][j]=p[i][j].x;
    	sort(p[i]+1, p[i]+n+1, cmp2);
    }
    sort(a+1, a+m+1, cmp);
    for (int i = 1;i <= m;i++)
    {
    	int x = a[i].u,y = a[i].v;
    	if (find(x) == find(y))
    		 continue;
    	merge(x,y);
    	v[x].push_back(y),v[y].push_back(x);
    	v2[x].push_back(a[i].w),v2[y].push_back(a[i].w);
    	ans += a[i].w;
    }
    if (k == 0)
    {
    	cout << ans << endl;
    	return 0;
    }
    for (int i = 1;i <= k;i++)
    	mn1[0][i] = p[i][1].x,ps[0][i] = 1;
    d = ans;
    solve1(1,0);
    dfs(1,0);
    cout << ans << endl;
	return 0;
}