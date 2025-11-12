#include<bits/stdc++.h>
#define ll long long

using namespace std;
const int N=2e5+9;
ll n,k,ch[N],m,fa[N],cost[N],cnt,ans;
struct edge{ll u,v,w;}e[N*20],ne[N*20];
inline bool cmp(edge x,edge y){
	return x.w<y.w;
}

inline void init(){
	for(int i=1;i<=n+10;i++)
		fa[i]=i;
}
inline int Find(int x){
	return fa[x]==x?x:fa[x]=Find(fa[x]);	
}

inline ll Kruskral(){
	init();
	sort(e+1,e+m+1,cmp);
	ll sum=0;
	for(int i=1;i<=m;i++){
		if(Find(e[i].u)!=Find(e[i].v)){
			sum+=e[i].w;
			fa[Find(e[i].u)]=Find(e[i].v);
			ne[++cnt]={e[i].u,e[i].v,e[i].w};
		}
	}
	return sum;
}

inline void check(){
	init();
	ll sum=0;
	for(int i=1;i<=k;i++)
		if(ch[i])sum+=cost[i]; 
	for(int i=1;i<=cnt;i++){
		if(ne[i].v<=n){
			if(Find(ne[i].u)!=Find(ne[i].v)){
				fa[Find(ne[i].u)]=Find(ne[i].v);
				sum+=ne[i].w;
			}
		}else{
			if(ch[ne[i].v-n] && Find(ne[i].u)!=Find(ne[i].v)){
				fa[Find(ne[i].u)]=Find(ne[i].v);
				sum+=ne[i].w;
			}
		}
	}
	ans=min(ans,sum);
}
inline void dfs(int x){
	if(x>k) return check();
	dfs(x+1);ch[x]=1;
	dfs(x+1);ch[x]=0;
	return void(); 
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>e[i].u>>e[i].v>>e[i].w;
	ans=Kruskral();
	for(int i=1;i<=k;i++){
		cin>>cost[i];
		for(int j=1;j<=n;j++){
			ne[++cnt].u=j;
			ne[cnt].v=i+n;
			cin>>ne[cnt].w;
		}
	}
	sort(ne+1,ne+cnt+1,cmp);
	dfs(1);
	
	cout<<ans;
	return 0;
}
/*
k<=10 that's so useful
however we can choose which black point we choose...
and use kruskral to find a amazing answer of this tree
why we must use all the black point??

if we won't use it,just like choose one of it edge
we can find a better answer without that bad black point
right?

it seems so beautiful 
but we should find how long time it will run
jsut nk*log(nk)*(2^k)
cost too much my bro..

change a dir? that is the only way I think it got possibility to the right way
we can't find the smallest tree in graph or we couldn't use dfs find which black point we use 

why? because find tree need O(m) that is you must do,and find black point need O(2^k)
but if we don't find black point we maybe can't know the cost of country....

so any easy way?

we guess we will only change the tree on the smallest one

if we change it on a bigger one,we will delete the max edge of u and v
but we can delete the max edge of u and v in smallest one,if bigger one is more valueable,
it means the max edge is so big ,but it still need run of u and v's smallest one edge,but smallest one won't go the biggest edge
so wonderful
*/
