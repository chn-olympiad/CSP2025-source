#include <bits/stdc++.h>
using namespace std;

inline int read()
{
	int w = 1,f = 0;
	char c = getchar();
	while(c < '0' or c > '9'){if(c == '-') w = -1;c = getchar();}
	while(c >= '0' and c <= '9') f = f * 10 + c - '0',c = getchar();
	return w * f; 
}

const int _ = 2e5 + 5;
int n,m,k;

vector <int> G[_];
vector <int> W[_];


struct node
{
	int x,dis;
	node(int x,int dis) : x(x),dis(dis){};
	bool operator < (const node &n1) const{
		return dis > n1.dis;
	}
};

priority_queue <node> q;

void add_edge(int u,int v,int w)
{
	G[u].push_back(v);
	G[v].push_back(u);
	W[u].push_back(w);
	W[v].push_back(w);
}

bool disable[_];//不可见节点 
bool vis[_];
int c[20];
long long ans;

int prim(int p,int base)//sum jiedian zongshumu
{
	memset(vis,0,sizeof vis);
	while(!q.empty()) q.pop();
	int sum = 0,num = 0;
	q.push(node(1,0));
	while(num < p)
	{
		int u = q.top().x;
		int dis = q.top().dis;
		q.pop();
//		cout << u << " " << q.top().dis <<  " " << q.size() << endl;
		if(vis[u]) continue;
		vis[u] = 1;
		
		sum += dis;
		if(sum + base > ans) return INT_MAX;
		
		
		++num;
		for(int j = 0;j < G[u].size();j++)
		{
			int v = G[u][j];
			int w = W[u][j];
			if(vis[v] or disable[v]) continue;
//			cout << "Fucking v" << v << endl;
			q.push(node(v,w));
		}
	}
	return sum;
}

int base;

void dfs(int i,int num)//启用节点数量 
{
	if(base >= ans) return;
//	cout << "fucking i" << i << endl; 
	if(i == k + 1)
	{
		ans = min(ans,(long long)base + prim(num,base));
		return;
	}
	if((base + ans + i + num) % 2)
	{
		disable[i + n] = 1;//0
		dfs(i + 1,num);
		
		
		disable[i + n] = 0;//1
		base += c[i];
		dfs(i + 1,num + 1);
		base -= c[i];
	}
	else
	{
		disable[i + n] = 0;//1
		base += c[i];
		dfs(i + 1,num + 1);
		base -= c[i];
		
		disable[i + n] = 1;//0
		dfs(i + 1,num);
		
	}
	return;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n = read();
	m = read();
	k = read();
	ans = INT_MAX; 
	for(int i = 1;i <= m;i++)
	{
		int u = read();
		int v = read();
		int w = read();
		add_edge(u,v,w);
	}
	
//	cout << prim(n);
//	return 0;
	for(int i = 1;i <= k;i++)
	{
//		int w = read();
//		add_edge(n + i,n + k + i,w);//n + k + i为代理节点 
		c[i] = read();
		for(int j = 1;j <= n;j++)
		{
			int w = read();
//			disable[n + i] = 1;
			add_edge(j,n + i,w);
		}
	}
	dfs(1,n);
	cout << ans;
//	cout << prim(n,0);
	return 0;
}
