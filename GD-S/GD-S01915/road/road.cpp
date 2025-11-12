/*
Neuvillette & Alhaitham
不要发呆，不要红温，对得起你的训练时间
题目名称 社团招新 道路修复 谐音替换 员工招聘
题目类型 传统型 传统型 传统型 传统型
目录 club road replace employ
可执行文件名 club road replace employ
输入文件名 club.in road.in replace.in employ.in
输出文件名 club.out road.out replace.out employ.out
每个测试点时限 1.0 秒 1.0 秒 1.0 秒 1.0 秒
内存限制 512 MiB 512 MiB 2048 MiB 512 Mi
*/
#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
constexpr int N=1e4+7;
constexpr int M=1e6+7;
constexpr int K=12;

using namespace std;
//边权值全部开long long 
int fa[N];
int n,m,k;
namespace k_0_kruskal
{
	int u,v; ll w;
	struct edge{int u,v;ll w;};
	vector<edge> e;
	int find(int u)
	{
		return fa[u]==u?u:fa[u]=find(fa[u]);
	}
	inline ll kruskal()
	{
		sort(e.begin(),e.end(),[&](edge A,edge B){return A.w<B.w;});
		ll ans=0;
		for(edge E:e)
		{
			int pu=find(E.u),pv=find(E.v);
			if(pu!=pv) ans+=E.w,fa[pu]=pv;
		}
		return ans;
	}
	inline ll solve()
	{
		for(int i=1;i<=m;i++)
		{
			cin>>u>>v>>w;
			e.push_back(edge{u,v,w});
			for(int i=1;i<=n;i++) fa[i]=i;
		}
		return kruskal();
	}
}
/*
每个k点都连边 
*/
namespace brute2
{
	struct edge{int u,v;ll w;
	bool operator<(edge B){
		return w<B.w;
	}};
	vector<edge> e,f,g;
	int find(int u)
	{
		return fa[u]==u?u:fa[u]=find(fa[u]);
	}
	ll c[N],a[K][N];
	bitset<K> vis;
	ll mn=1e18;
	inline ll kruskal()
	{
		f.clear();
		for(int i=1;i<=n+k;i++) fa[i]=i;
		for(int i=1;i<=k;i++) if(vis[i])
		{
			for(int j=1;j<=n;j++)
			{
				f.emplace_back(edge{i+n,j,a[i][j]});
			}
		}
		sort(f.begin(),f.end(),[&](edge A,edge B){return A.w<B.w;});
		g.resize(f.size()+e.size()+5);
		merge(f.begin(),f.end(),e.begin(),e.end(),g.begin());
		ll ans=0;
		for(edge E:g)
		{
			int pu=find(E.u),pv=find(E.v);
			if(pu!=pv) ans+=E.w,fa[pu]=pv;
		}
		return ans;
	}
	void dfs(int dep,ll w)  //w额外代价 
	{
		if(dep>k)
		{
			ll res=kruskal()+w;
//			for(int i=1;i<=k;i++) cerr<<vis[i]<<',';
//			cerr<<"ans="<<res<<endl;
			mn=min(mn,res);
			return ;
		}
		vis[dep]=1;dfs(dep+1,w+c[dep]);vis[dep]=0;
		dfs(dep+1,w);
	}
	inline ll solve()
	{
		int u,v; ll w;
		for(int i=1;i<=m;i++)
		{
			cin>>u>>v>>w;
			e.push_back(edge{u,v,w});
		}
		sort(e.begin(),e.end(),[&](edge A,edge B){return A.w<B.w;});
		for(int j=1;j<=k;j++)
		{
			cin>>c[j];
			for(int i=1;i<=n;i++) cin>>a[j][i];
		}
		dfs(1,0);
		return mn;
	}
}
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0)
	{
		cout<<k_0_kruskal::solve()<<endl;
		cout.flush();
	}
	else
	{
		cout<<brute2::solve()<<endl;
		cout.flush();
	}
	cout.flush();
	return 0;
}
/*
让我1s过1e9可以不？？？？？/kel 
*/
/*
最小生成树 kruskal 加油，早上刚复习过的，可以打出来 
一共有M+N^2*K条边
*/
/*
乡村城市化需要c的点权，怎么办？暴力方法是2^k枚举 
*/
/*
T3貌似可以不可以总司令？ 
*/
/*
对拍代码：
#include<bits/stdc++.h>
#include<windows.h>
typedef long long ll;
typedef unsigned long long ull;
constexpr int N=-1;
using namespace std;
int main()
{
	while(1)
	{
		system("club.exe");
		system("baoli.exe");
		system("data.exe");
		int res=system("fc club.out club.ans");
		if(res==1)
		{
			cout<<"WA\n";
			MessageBox(NULL,"WA","WA",MB_ICONERROR);
			system("pause");
		}
	}
	return 0;
} 
*/
