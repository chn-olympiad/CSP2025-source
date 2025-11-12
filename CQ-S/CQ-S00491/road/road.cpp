#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
typedef pair < long long, long long > PII;
const int M = 1e6 + 5, N = 1e4 + 5;
int n, m, k;
vector < PII > G[N];
// vector < pair < long long, PII > > Sid;
vector < PII > G1[N];
struct Point{
	long long val;
	long long w[N];
	bool vis[N];
}P[15];
bool vis[N];
//string s;
void Prim()
{
	priority_queue < pair < long long, PII >, vector < pair < long long, PII > >, greater < pair < long long, PII > > > q;
	for(auto i : G[1])q.push({i.sec, {1, i.fir}});
	vis[1] = 1;
	while(!q.empty())
	{
//		cerr << "?"; 
		auto cur = q.top();
		q.pop();
		long long u = cur.sec.sec, fa = cur.sec.fir, val = cur.fir;
		if(vis[u])continue;
		vis[u] = 1;
		G1[u].push_back({fa, val});
		G1[fa].push_back({u, val});
		for(auto i : G[u])
		{
			long long v = i.fir, w = i.sec;
			if(!vis[v] && v != fa)q.push({w, {u, v}});
		}
	}
}
long long bfs()
{
	queue < pair < PII, long long > > q;
	q.push({{1, 0}, 0});
	long long ans = 0;
	while(!q.empty())
	{
		auto cur = q.front();
		q.pop();
		int u = cur.fir.fir, fa = cur.fir.sec, flag = cur.sec;
		for(auto i : G1[u])
		{
			int v = i.fir;
			long long w = i.sec, vvis = 0;
			if(v == fa)continue;
			for(int i = 1; i <= k; i++)
			{
				if(i == flag)
				{
					if(P[i].w[v] <= w)
					{
						vvis = i;
						w = P[i].w[v];
					}
				}else{
					if(P[i].w[u] + P[i].w[v] + P[i].val <= w)
					{
						vvis = i;
						w = P[i].w[u] + P[i].w[v] + P[i].val;
					}
				}
			}
			ans += w;
			q.push({{v, u}, vvis});
		}
	}
	return ans;
}
long long solve()
{
	long long ans = 0;
	ans = bfs();
	return ans;
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	// freopen("input.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	// for(int i = 1; i <= m; i++)cin >> G[i].u >> G[i].v >> G[i].w;
	for(int i = 1; i <= m; i++)
	{
		long long u, v, w;
		cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	for(int i = 1; i <= k; i++)
	{
		cin >> P[i].val;
		for(int j = 1; j <= m; j++)cin >> P[i].w[j];
	}
	Prim();
	long long ans = solve();
	cout << ans;
	return 0;
}
/*
啊？2.148e8？？？你告诉我是这个复杂度？？？还只给1000ms。无语ing……（15：32）
希望评测机能跑得快一点吧，球球了，我T1都没有做出来，看着是贪心，结果写完才发现第三个样例不对，气鼠我了！（15：44）
哦，我刚刚才发现是3.048e7，算错了，唬我一脸……（16：45）
我觉得我想出正解了，3.024e7，应该能过吧……（16：55）
我好像又又又又算错时间复杂度了（17：04）
啊啊啊为什么大样例超时了！！！（17：58）
哦！我又又又知道了！有些步骤根本不需要！（17：58）
服了，为什么第2个大样例输出0啊！！！！！我要爆零了！！！！！！！！！！！我T1崩溃不想做了！！！T2只过了小样例！（18：28）
*/
