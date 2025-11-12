#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0;
	char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x;
}
int n,m,k,c[12];
struct edge{
	int u,v,w;
	inline bool operator<(const edge &other){
		return w<other.w;
	}
}e[1100005];
bool res[12];
int fa[10015],si[10015];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
//	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		e[i].u=read();e[i].v=read();e[i].w=read();
//		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	}
	int tot=m;
	bool isa=1;
	for(int i=1;i<=k;i++){
		c[i]=read();
		if(c[i]) isa=0;
		bool tmp=0;
		for(int j=1;j<=n;j++){
			e[++tot].w=read();
			if(!e[tot].w) tmp=1;
			e[tot].u=j;
			e[tot].v=n+i;
		}
		if(!tmp) isa=0;
	}
	sort(e+1,e+m+k*n+1);
	long long ans=1e14;
	if(isa){
		for(int i=1;i<=n+k;i++){
			fa[i]=i;
			si[i]=1;
		}
		long long sum=0;
		int num=n+k,eg=0;
		for(int i=1;i<=m+k*n&&eg<num-1;i++){
			int u=find(e[i].u),v=find(e[i].v);
			if(u!=v){
				eg++;
				sum=sum+e[i].w;
				if(si[u]<si[v]){
					fa[u]=v;
					si[v]+=si[u];
				}else{
					fa[v]=u;
					si[u]+=si[v];
				}
			}
		}
		printf("%lld",sum);
		return 0;
	}
	for(int cho=0;cho<(1<<k);cho++){
		for(int i=1;i<=n+k;i++){
			fa[i]=i;
			si[i]=1;
		}
		int CHO=cho,num=n,eg=0;
		long long sum=0;
		for(int i=1;i<=k;i++){
			res[i]=CHO&1;
			if(res[i]){
				sum=sum+c[i];
				num++;
			}
			CHO>>=1;
		}
		for(int i=1;i<=m+k*n&&eg<num-1;i++){
			if(e[i].v<=n||res[e[i].v-n]){
				int u=find(e[i].u),v=find(e[i].v);
				if(u!=v){
					eg++;
					sum=sum+e[i].w;
					if(si[u]<si[v]){
						fa[u]=v;
						si[v]+=si[u];
					}else{
						fa[v]=u;
						si[u]+=si[v];
					}
				}
			}
		}
		ans=min(ans,sum);
//		printf("%lld\n",sum);
	}
	printf("%lld",ans);
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
