#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+100,M=5e7+100;
int n,m,k,cnt,num;
ll ans;
int fa[N+100];
struct node{
	int x,y;
	ll w;
}e[M];
int chu[10][N];
int find(int x){
	while(x!=fa[x]) x=find(fa[x]);
	return fa[x]=x;
}
bool cmp(node x,node y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	ll w;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d%lld",&u,&v,&w);
		e[++cnt].x=u;
		e[cnt].y=v;
		e[cnt].w=w;
	}
	ll x,y;
	for(int i=1;i<=k;i++){
		scanf("%lld",&x);
		for(int j=1;j<=n;j++){
			scanf("%lld",&y);
		}
	}
	sort(e+1,e+1+cnt,cmp);
	num=1;
	for(int i=1;i<=cnt;i++){
		int x=e[i].x,y=e[i].y,w=e[i].w;
		int x1=find(x),y1=find(y);
		if(x1!=y1){
			fa[x1]=y1;
			num++;
			ans+=w;
		}
		if(num>=n) break;
	}
	printf("%lld\n",ans);
	return 0;
}
