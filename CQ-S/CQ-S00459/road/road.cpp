#include<bits/stdc++.h>
#define int long long
#define File(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
using namespace std;
int n,m,k2,c[15],ab[15][10005],ans=LLONG_MAX,b[10005];
vector<tuple<int,int,int>>a[15];
vector<tuple<int,int,int>>edge;
vector<tuple<int,int,vector<tuple<int,int,int>>>>e;
inline int find(int u)
{
	while(b[u]!=u)
	{
		int t=b[u];
		b[u]=b[b[u]]; 
		u=t;
	}
	return u;
}
signed main()
{
	File("road"); 
	ios::sync_with_stdio(false);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m>>k2;
	for(int i=1;i<=m;i++)
	{
		int u,v,k;
		cin>>u>>v>>k;
		edge.emplace_back(k,u,v);
	}
	for(int i=1;i<=k2;i++)
	{
		cin>>c[i];
		int mi=LLONG_MAX,miid=0;
		for(int j=1;j<=n;j++)
		{
			cin>>ab[i][j];
			if(ab[i][j]<=mi)
				mi=ab[i][j],miid=j;
		}
		c[i]+=ab[i][miid]; 
		for(int j=1;j<=n;j++)
			if(j!=miid)
				a[i].emplace_back(ab[i][j],miid,j);
	}
	for(int i=1;i<=n;i++)
		b[i]=i;
	int num=0;
	sort(edge.begin(),edge.end());
	vector<tuple<int,int,int>>tmpp;
	for(auto [k,u,v]:edge)
	{
		int fu=find(u),fv=find(v);
		if(fu==fv)
			continue;
		b[fv]=b[fu];
		tmpp.emplace_back(k,u,v);
		num+=k;
	}
//	cerr<<num<<'\n';
	ans=min(ans,num);
	e.emplace_back(0,num,tmpp);
	for(int _=1;_<=k2;_++)
	{
		vector<tuple<int,int,vector<tuple<int,int,int>>>>data;
		for(auto [add,lastans,tmpe]:e)
		{
			vector<tuple<int,int,int>>redge;
			for(auto [k,u,v]:a[_])
				tmpe.emplace_back(k,u,v);
			for(int i=1;i<=n;i++)
				b[i]=i;
			int num=0;
			sort(tmpe.begin(),tmpe.end());
			int cnt=0;
			for(auto [k,u,v]:tmpe)
			{	
//				cerr<<k<<' '<<u<<' '<<v<<'\n';
				int fu=find(u),fv=find(v);
				if(fu==fv)continue;
				b[fv]=b[fu];
				redge.emplace_back(k,u,v);
				++cnt;
				num+=k;
			}
//			cerr<<"CNT="<<cnt<<'\n';
			add+=c[_];
			ans=min(ans,num+add);
			if(lastans>num+add)
				data.emplace_back(add,num+add,redge);
//			cerr<<_<<' '<<num+add<<'\n';
		}
		for(auto datt:data)
			e.emplace_back(datt);
	}
//	cerr<<ans; 
	cout<<ans;
	return 0;
}
/*
14:48 
神秘图论（？） 
奇怪的最小生成树？
k<=10
但是显然不可能用阶乘的复杂的枚举城市化的乡村
乡村的效果相当于消费ci获得任意两个城市的边，
但是显然不可能把新边全部枚举一遍
如果初始没用某条边，那后面也不可能用那条边
似乎可以直接找到最小的a_i
然后把其他点都尝试挂上去
一个乡村新增的边数就成n条了 

这样显然最优（？）
试试
先跑最小生成树
然后把树建出来
然后x连y可以选择断掉x~y这条链的任意一条边
所以肯定是选最大的
要查一条链上的最大边
考虑

直接把乡村挂上去然后再用新的边跑一轮最小生成树

可以吗？
试试,WA了再换方法 

然后存k+1版本

如果升级乡村x和y比乡村x劣，那显然不用保留这两种，如果更优，那就都保留
然后每个乡村最多会枚举到一次
每次枚举会执行最多
时间复杂度最多O(nlogn2^k)，能过 
开写 

为什么会WA?

16:10

为什么第4个大样例WA了？



6,我建了一堆到miid的边，改一下 
16:40

AC
16:51
*/
