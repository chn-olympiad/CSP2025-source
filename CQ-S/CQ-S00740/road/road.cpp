//the code is from chenjh
#include<bits/stdc++.h>
#define MAXN 10015
#define MAXM 1000005
using namespace std;
typedef long long LL;
int n,m,k;
struct Edge{
	int u,v,w;
	Edge(const int _u=0,const int _v=0,const int _w=0):u(_u),v(_v),w(_w){}
	bool operator < (const Edge&B)const{return w<B.w;}
}e[MAXM];
vector<Edge> G;
int fa[MAXN];
int find(const int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
LL ans=0;
int c[11];
vector<Edge> a[11];
void dfs(const int p,vector<Edge> E,const LL&cs){
	if(p>k) return;
	dfs(p+1,E,cs);
	vector<Edge> F;
	E.insert(E.end(),a[p].begin(),a[p].end()); 
	inplace_merge(E.begin(),E.end()-a[p].size(),E.end());
	iota(fa+1,fa+n+k+1,1);
	LL now=cs+c[p];
	for(auto [u,v,w]:E){
		u=find(u),v=find(v);
		if(u!=v) now+=w,fa[v]=u,F.emplace_back(u,v,w);
	}
	ans=min(ans,now);
	swap(E,F),F.clear(),F.shrink_to_fit();
//	fprintf(stderr,"%lld\n",now);
//	for(const auto&[u,v,w]:E) fprintf(stderr,"%d %d %d\n",u,v,w);
	dfs(p+1,E,cs+c[p]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>m>>k;//scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;//scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	sort(e+1,e+m+1);
	iota(fa+1,fa+n+1,1);
	for(int i=1;i<=m;i++){
		auto [u,v,w]=e[i];
		u=find(u),v=find(v);
		if(u!=v) ans+=w,fa[v]=u,G.emplace_back(u,v,w);
	}
//	for(const auto&[u,v,w]:G) fprintf(stderr,"%d %d %d\n",u,v,w);
	for(int i=1;i<=k;i++){
		cin>>c[i],//scanf("%d",&c[i]),
		a[i].resize(n);
		int j=0;
		for(Edge&x:a[i])
			cin>>x.w,//scanf("%d",&x.w),
			x.u=n+i,x.v=++j;
		sort(a[i].begin(),a[i].end());
	}
	dfs(1,G,0);
	cout<<ans<<'\n';//printf("%lld\n",ans);
	return 0;
}
/*


Change:



Idea:

题目保证这是一个无向联通图。

注意到 k 很小。

可以接受 O(2^k n) 的做法，多个 k 应该也没关系。 

m 是不是大多数都是没用的。

根据最小生成树的唯一性，建出来后做删边替换，也不存在加边。

题目好像看错了，这个点是新加入的。

相当于是加点后的最小生成树。 

这个数据好像不太满。

造一个大点的。 

Command:

g++ road.cpp -o road -O2 -std=c++14 -Wall -Wextra -Wshadow -static
g++ road.cpp -o road -O2 -std=c++14 -Wall -Wextra -Wshadow -fsanitize=address,undefined,signed-integer-overflow -g

copy .\data\road\road1.in road.in /Y
copy .\data\road\road1.ans road.ans /Y
.\road
fc road.out road.ans

copy .\data\road\road2.in road.in /Y
copy .\data\road\road2.ans road.ans /Y
.\road
fc road.out road.ans

copy .\data\road\road3.in road.in /Y
copy .\data\road\road3.ans road.ans /Y
.\road
fc road.out road.ans

copy .\data\road\road4.in road.in /Y
copy .\data\road\road4.ans road.ans /Y
.\road
fc road.out road.ans

cp ../data/road/road1.in road.in
cp ../data/road/road1.ans road.ans
time ./road
diff road.out road.ans -BZ

cp ../data/road/road2.in road.in
cp ../data/road/road2.ans road.ans
time ./road
diff road.out road.ans -BZ

cp ../data/road/road3.in road.in
cp ../data/road/road3.ans road.ans
time ./road
diff road.out road.ans -BZ

cp ../data/road/road4.in road.in
cp ../data/road/road4.ans road.ans
time ./road
diff road.out road.ans -BZ

*/

