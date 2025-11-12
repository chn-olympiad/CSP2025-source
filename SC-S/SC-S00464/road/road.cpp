#include<bits/stdc++.h>
using namespace std;
#define MAXN 10104
#define MAXM 4000006
//int head[MAXN],to[MAXM],nxt[MAXM],cnt;
//long long value[MAXM];
//inline void add(int u,int v,int w){
//	nxt[++cnt]=head[u];
//	to[cnt]=v;
//	head[u]=cnt;
//	value[cnt]=w;
//}
struct Edge{
	int u,v,w;
}E[MAXM];
bool ifgo[MAXN];
bool comp(Edge &a,Edge &b){
	return a.w<=b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int n,m,k;
	long long cost=0;
	scanf("%d%d%d",&n,&m,&k);
	int cnt=1;
	for(;cnt<=m;++cnt){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		E[cnt].u=u,
		E[cnt].v=v,
		E[cnt].w=w;
		
//		add(u,v,w);
//		add(v,u,w);
	}
	--cnt;
	int nn=n;
	for(int i=1;i<=k;++i){
		int num;
		scanf("%d",&num);
		for(int j=1;j<=nn;++j){
			int w;
			scanf("%d",&w);
			++cnt;
			E[cnt].u=j;
			E[cnt].v=nn+i;
			E[cnt].w=w;
		}
		++n;
		if(num){
			cost+=num;
			break;
		}
	}
//	printf("%d\n\n",cnt);
//	cout<<"haha"<<endl;
	sort(E+1,E+cnt+1,comp);
	{
		int cnte=1,i=1;
		while(cnte<n && i<=cnt){
			if((!ifgo[E[i].u]) || (!ifgo[E[i].v])){
				cost+=E[i].w;
				ifgo[E[i].u]=1;
				ifgo[E[i].v]=1;
				++cnte;
//				printf("%d %d\n",cnte,i);
//				printf("%d %d %d**%d*\n",E[i].v,E[i].u,E[i].w,cnte);
			}
			++i;
		}
//		printf("%d %d %d\n",cnte,i,n);
	}
	printf("%lld",cost);
	return 0;
}
/*

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/