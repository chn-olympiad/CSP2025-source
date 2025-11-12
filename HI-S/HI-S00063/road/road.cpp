#include <bits/stdc++.h>

using namespace std;
int const maxN=10010,maxM=1000010; 
int n,m,k;
long long ans;
struct edge{
	int u,v,w;
}e[maxM];
struct dian{
	int c,a[maxN];
}xz[12];
queue <int> q;
bool ins[maxN];
int head[maxN],nxt[maxM],cnt;
void add_edge(int u,int v,int w){
	cnt++;
	e[cnt].u=u;
	e[cnt].v=v;
	e[cnt].w=w;
	nxt[cnt]=head[u];
	head[u]=cnt;
}
void work(){
	long long minn=1000000010;
	int u1,u2;
	for(int i=1;i<=m;i++){
		if(e[i].w<minn){
			minn=e[i].w;
			u1=e[i].u,u2=e[i].v;
		}
	}
	ans+=minn;
	q.push(u1);
	q.push(u2);
	ins[u1]=ins[u2]=1;
	while(!q.empty()){
		int u=q.front();
		minn=1000000010;
		for(int i=head[u];i=-1;i=nxt[i]){
			if(e[i].w<minn){
				if(ins[e[i].v]!=1){
					ins[e[i].v]=1;
					minn=e[i].w;
					u2=e[i].v;
				}
			}
		}
		ans+=minn;
		ins[u2]=1;
		q.pop();
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++) head[i]=-1;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
		add_edge(e[i].u,e[i].v,e[i].w);
		add_edge(e[i].v,e[i].u,e[i].w);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&xz[i].c);
		for(int j=1;j<=n;j++){
			scanf("%d",&xz[i].a[j]);
		}
	}
	if(k<=0){
		work();
	}else{
		printf("0"); 		
	}	
	return 0;
}
//4 4 2
//1 4 6
//2 3 7
//4 2 5
//4 3 4
//1 1 8 2 4
//100 1 3 2 4
