#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9 + 7;
const int N = 114514;
const int M = 15;

int n,m,k;

struct edge
{
	int u,v,w;
};

vector<edge> E;

vector<edge> e[M];

int f[N];

bool cmp(const struct edge &t1,const struct edge &t2)
{
	return t1.w < t2.w;
}

int cnt = 0;

void init()
{
	for (int i = 1 ; i <= cnt ; i ++) f[i] = i;
//	std :: cout << "\n=========================\n";
//	for (int i = 1 ; i <= cnt ; i ++) std :: cout << f[i] << " ";
//	std :: cout << "\n=========================\n";
}

int c[N];

int find(int x)
{
	if (f[x] == x) return f[x];
	f[x] = find(f[x]);
	return f[x];
}

void add(int x,int y)
{
	int a = find(x),b = find(y);
	f[b] = a;
	return; 
}

int ans = INF;

vector<edge> backup_E;

void solve(int status)//Ã¶¾Ù×´Ì¬ 
{
	backup_E = E;
	int tcnt = 0;
	int now_ans = 0;
	cnt = n;
	while (status)
	{
		tcnt ++;
		if (status & 1)//ÐÞ¸´¸Ã´å×¯ 
		{
			//std :: cout << "fix" << tcnt << "\n";
			cnt ++;
			for (auto &t : e[tcnt]) E.push_back(t);
			now_ans += c[tcnt];
		}
		status >>= 1;
	}
	//std :: cout << cnt << "!!!!!!\n";
	init();
	//for (int i = 1 ; i <= cnt ; i ++) std :: cout << f[i] << " ";
	sort(E.begin(),E.end(),cmp);
//	for (auto &t : E)
//	{
//		std :: cout << t.u << " " << t.v << " " << t.w << "\n";
//	}
	//for (int i = 1 ; i <= cnt ; i ++) std :: cout << f[i] << "\n";
	int ccnt = 0;
	//std :: cout << "cnt:" << cnt << "\n";
	for (auto &t : E)
	{
		int u = t.u;
		int v = t.v;
		int w = t.w;
		if (find(u) != find(v))
		{
			now_ans += w;
			if (now_ans > ans) 
			{
				E = backup_E;
				return;
			}
			//std :: cout << w << "\n";
			add(u,v);
			ccnt ++;
			if (ccnt == cnt - 1)
			{
				break;
			}
		}
	} 
	E = backup_E;
	ans = std :: min(ans,now_ans);
}

int main()
{
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	std :: cin >> n >> m >> k;
	for (int i = 1 ; i <= m ; i ++)
	{
		int u,v,w;
		std :: cin >> u >> v >> w;
		E.push_back({u,v,w});
	}
	for (int i = 1 ; i <= k ; i ++)
	{
		std :: cin >> c[i];
		for (int j = 1 ; j <= n ; j ++)
		{
			int x;
			std :: cin >> x;
			e[i].push_back({cnt,j,x});
		}
	}
	for (int i = 0 ; i < (1 << k) ; i ++) solve(i);
	std :: cout << ans;
} 
