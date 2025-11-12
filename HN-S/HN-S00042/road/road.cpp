#include<bits/stdc++.h>
using namespace std;
const int M = 2e6 + 10,N = 2e5 + 10;
int fa[N],n,m,k,chan[20][N],ly[20],tl;
long long sum = 0;
struct Node{
	int u,v,w,bl = 0;
};
struct hk{
	int v,w;
};
vector<hk> e[N];
Node rd[M];
bool cmp(Node a,Node b)
{
	return a.w < b.w;
}

int find(int x)
{
	if(fa[x] == x)return x;
	return fa[x] = find(fa[x]);
}

void th(int i)
{
	if(!i)return;
	n++;
	for(int j = 1 ; j <= tl ; j++)
		rd[++m].u = n,rd[m].v = j,rd[m].w = chan[i][j] + ly[i];
}

void Krus()
{
	sort(rd + 1,rd + m + 1,cmp);
	int k = 0,lp;
	for(int i = 1 ; i <= m ; i++)
	{
		int u = find(rd[i].u),v = find(rd[i].v);
		if(u == v)continue;
		else 
		{
			fa[u] = v,k++,lp = i;
			rd[i].bl = 1;
			e[rd[i].u].push_back({rd[i].v,rd[i].w});
			e[rd[i].v].push_back({rd[i].u,rd[i].w});
		}
		if(k == (n - 1))break; 
	}
}
bool vis[N];
void dfs(int s)
{
	queue<int> q;
	q.push(s);
	while(!q.empty())
	{
		int t = q.front();
		q.pop();
		vis[t] = true;
		for(int i = 0 ; i < e[t].size() ; i++)
		{
			int v = e[t][i].v;
			if(vis[v])continue;
			if(v > tl && e[v].size() == 1)continue;
			sum += e[t][i].w;
			if(t > tl)sum -= ly[t - tl];
			q.push(v);
		}
	}
}
int read()
{
	int x = 0;
	char c = getchar();
	while(c < '0' || c > '9')c = getchar();
	while(c >= '0' && c <= '9')
	{
		x = (x << 1) + (x << 3) + c - '0';
		c = getchar();
	}
	return x;
 } 

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n = read(),m = read(),k = read();
	for(int i = 1 ; i <= m ; i++)rd[i].u = read(),rd[i].v = read(),rd[i].w = read();
	for(int i = 1 ; i <= k ; i++)
	{
		ly[i] = read();
		for(int j = 1 ; j <= n ; j++)
			chan[i][j] = read();
	}
	long long ans = -1;
	tl = n;
	for(int op = 0 ; op <= k ; op++)th(op);
	for(int i = 1 ; i <= tl + k ; i++)fa[i] = i,vis[i] = 0,e[i].clear();
	Krus(),dfs(1);
	if(ans == -1)ans = sum;
	else ans = min(ans,sum);
	cout<<ans;
	return 0;
 } 
