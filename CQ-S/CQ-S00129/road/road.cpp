#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int NR = 1e4 + 10 + 10;
const int KR = 15;
const int MR = 1e6 + 10 + NR * KR;
int n,m,k;
struct edge
{
	int x,y;
	ll w;
}e[MR] , etmp[MR];
bool vis[NR];
bool p[KR];
ll c[KR];
ll a[KR][NR];
int fa[NR];

//我了160行MST+dfs。。 16:53 

bool cmp(edge x,edge y)
{
	return x.w < y.w;
}

int find(int u)
{
	if(u == fa[u])return u;
	return fa[u] = find(fa[u]);
}
ll ans = 9e18;
int idx = 0;

void dfs(int step , ll tmp)//第step个村庄到底要不要建设 
{
	if(tmp > ans)return ;
	if(step > k)
	{
		//MST
		memset(vis,0,sizeof(vis)) , memset(fa,0,sizeof(fa));
		memcpy(etmp,e,sizeof(e));
		int h = idx;
		for(int i=1;i<=k;i++)
		{
//			cout<<p[i]<<" ";
			if(p[i] == 0)continue;
//			tmp += c[i];
			for(int j=1;j<=n;j++)
			{
				etmp[++h] = {i + n,j,a[i][j]};
			}
		}
//		cout<<endl;
		for(int i=1;i<=n+k;i++)
		{
			if(i > n && p[i-n] == 0)continue;
			fa[i] = i;
		}
		sort(etmp + 1 , etmp + h + 1 , cmp);
		ll cnt = 0;
		for(int i=1;i<=h;i++)
		{
			int x = etmp[i].x , y = etmp[i].y;
			ll w = etmp[i].w;
			int fx = find(x) , fy = find(y);
			if(fx != fy)
			{
				fa[fx] = fy;
				tmp += w;
				if(x <= n && !vis[x])cnt++ , vis[x] = 1;
				if(y <= n && !vis[y])cnt++ , vis[y] = 1;
			}
			if(cnt == n)break;//保证基础节点联通 
		}
//		cout<<tmp<<endl;
		ans = min(ans , tmp);
		return ; 
	}
	p[step] = 0;
	dfs(step + 1 , tmp);
	p[step] = 1;
	dfs(step + 1 , tmp + c[step]);
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		ll w;
		cin>>x>>y>>w;
		e[++idx] = {x,y,w};
//		e[++idx] = {y,x,w};
	}
	ll maxn = -9e18; 
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		maxn = max(maxn , c[i]);
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	
	if(maxn == 0)//特殊性质A 32pts
	{
		//MST
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=n;j++)
			{
				e[++idx] = {i + n,j,a[i][j]};
//				e[++idx] = {j,i,a[i][j]};
			}
		}
		//因为节点免费创造，直接当成正常节点MST 
		n += k;
		for(int i=1;i<=n;i++)fa[i] = i;
		sort(e + 1 , e + idx + 1 , cmp);
		ans = 0;
		ll cnt = 0;
		for(int i=1;i<=idx;i++)
		{
			int x = e[i].x , y = e[i].y;
			ll w = e[i].w;
			int fx = find(x) , fy = find(y);
			if(fx != fy)
			{
				fa[fx] = fy;
				ans += w;
				if(x <= n - k && !vis[x])cnt++ , vis[x] = 1;
				if(y <= n - k && !vis[y])cnt++ , vis[y] = 1;
//				cout<<x<<" "<<y<<endl;
			}
			if(cnt == (n-k))break;//保证基础节点联通 
		}
		cout<<ans<<endl;
		return 0;
	}
	dfs(1 , 0);//O(2^k * mlogm) k<=5时可过 40pts 
	cout<<ans<<endl;
	return 0;
}
/*
思路1：
dfs+MST 
乡村的全排列+prim+剪枝 + 特殊性质A
8 * 4 + 10 * 4 = 72pts 

k<=5时和有特殊性质A时 
*/
