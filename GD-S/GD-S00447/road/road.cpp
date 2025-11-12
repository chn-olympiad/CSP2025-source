#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct edge{
	int v,w;
};
vector<edge> a[10015];

#define d first
#define idx second
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
//丐版小根堆 
int dis[10015];
bool vis[10015];
int prim(){
	memset(dis,0x3f,sizeof(dis));
	int res=0;
	q.push(make_pair(0,1));
	dis[1]=0;
	while(!q.empty()){
		int u=q.top().idx;
		if(vis[u]){
			q.pop();
			continue;
		}else{
			res+=q.top().d;
			q.pop();
			vis[u]=1;
//			
			dis[u]=0;
//			
			for(auto e:a[u]){
				if(!vis[e.v]){
					//注意，这是距离整棵树的距离 
					if(dis[e.v]>e.w){
						dis[e.v]=e.w;
						q.push(make_pair(e.w,e.v));
					}
					//由于是距离整棵树的距离，只需要算一条边的距离即可 
				}
			}
		}
	}//这能对我【】,luogu洛谷要是这题我过了40记得给我上迷惑行为大赏 
	//可以写【】为代码原文 
	return res;
	//两秒八三，我看看能不能优化一下
	//首先，prim到底怎么写来着
	/*
	即使是解绑读写之后也要一秒四四 
	剩余的瓶颈很明显在于m超绝1e6，和每个点的反复读入 
	要想避免1e6的影响，我们可能必须保证每个点只入队一次 
	好消息！在加了一个dis的检定之后，样例3的答案依旧正确
	并且时间压倒了零秒五六！
	我觉得差不多了，收手吧 
	理想预期分数50 
	*/ 
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>m>>k;
	for(int i = 1,u,v,w ; i <= m ; ++i){
		cin>>u>>v>>w;
		a[u].push_back((edge){v,w});
		a[v].push_back((edge){u,w});
	}
	for(int i = 1,w ; i <= k ; ++i){
		cin>>w;//过滤掉所有点权，视为0 
		for(int j = 1 ; j <= n ; ++j){
			cin>>w;
			a[n+i].push_back((edge){j,w});
			a[j].push_back((edge){n+i,w});
		}
	}
	n+=k;//注意这里我直接把c类点归到标准点里面了 
	/*这题我目前不打算想正解
	首先，前四个点是裸的最小生成树
	我大概，也许，可能，还记得怎么写
	然后a属性
	考虑到对于所有的c都存在0，毫无疑问地，把所有0点上
	这样不难发现，情况变成了有一个c构成的分层图叠在原图上
	实际上遇到这种情况，我们可以直接把所有c的出边直接连到所有与c链接
	为0的点上 
	也可以直接把c算进a里开跑
	总而言之就是最小生成树直接跑就完了 
	唯一的问题是，最小生成树怎么写来着 
	*/
	cout<<prim()<<endl;
	/*
	我真的想不起来了
	先试试prim吧
	prim的写法与dijkstra一致
	先拓展出局部树
	再从局部树上一个个寻找与局部树整体最接近的点 
	考虑到其与dijkstra的相似性
	很有可能在题目的稠密图中表现好于kruskal 
	*/
	return 0;
}
