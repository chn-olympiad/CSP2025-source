#include <cstdio>
using namespace std;

int n,m,k,cnt,ans,h[10005];
struct node{
	int u,v,w;
}e[1000005];
void add(int u,int v,int w){
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].w=w;
	h[u]=cnt;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++) {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		ans+=w;
	}
	printf("%d",ans);
	return 0;
}
