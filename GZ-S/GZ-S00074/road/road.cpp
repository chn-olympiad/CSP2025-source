//GZ-S00074 遵义市南白中学 卢杰子豪 
#include<fstream>
#include<queue>
#include<forward_list>
#include<cmath>

std::ifstream in("road.in");
std::ofstream out("road.out");

using ll = long long;
constexpr int msiz = 1e4+15;
struct node
{
	std::forward_list<int> to;
	std::forward_list<int> w;
}nodes[msiz];
inline void push(int u,int v,int w)
{
	static bool view[msiz][msiz];
	if(view[u][v]||u==v)
		return;
	view[u][v]=view[v][u]=true;
	nodes[u].to.push_front(v);
	nodes[v].to.push_front(u);
	nodes[u].w.push_front(w);
	nodes[v].w.push_front(w);
}
ll result;
ll prim(int n)
{
	bool view[msiz];
	int view_size = 0;
	std::priority_queue<std::pair<int,int>> pq;
	pq.push({0,1});
	while(view_size!=n)
	{
		auto pr = pq.top();
		pq.pop();
		int w = -pr.first;
		int to = pr.second;
		view[to] = true;
		++view_size;
		result+=w;
		auto wp = nodes[to].w.begin();
		auto tp = nodes[to].to.begin();
		while(wp!= nodes[to].w.end())
		{
			if(!view[*tp])
				pq.push({-*wp,*tp});
			++wp,++tp;
		}
	}
	return result;
}
int main()
{
	int n,m,k,u,v,w;
	in>>n>>m>>k;
	while(m--)
	{
		in>>u>>v>>w;
		push(u,v,w);
	}
	ll last = prim(n);
	result=u=0;
	while(k--)
	{
		++u;
		in>>m;
		result+=m;
		for(v=1;v<=n;v++)
		{
			in>>w;
			push(n+u,v,w);
		}
	}
	out<<std::min(u==0?last:prim(n+u),last);
	return 0;
}
