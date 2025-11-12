#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N=1e4+100,M=1e6+100;
int n,m,k,c[15],a[15][N],fa[N],siz[N];
struct node{int x,y,w;}e[M];
bool operator<(const node &x,const node &y){return x.w<y.w; }
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
	x=find(x),y=find(y);
	if(x!=y){
		if(siz[x]>siz[y])swap(siz[x],siz[y]);
		fa[x]=y,siz[y]+=siz[x];
	}
}
node g[M<<1],t[M<<1];int kg,kt;
int main(){
	// freopen("1.in","r",stdin);
	// freopen("1.out","w",stdout);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);int mx=0;
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].w);
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);mx=max(mx,c[i]);
		for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
	}
	sort(e+1,e+m+1);ll ans=0;
	vector<node>ve;
	for(int i=1;i<=n+k;i++)fa[i]=i,siz[i]=1;
	for(int i=1;i<=m;i++){
		int x=e[i].x,y=e[i].y,w=e[i].w;
		if(find(x)!=find(y)){
			merge(x,y);ans+=w;ve.push_back(e[i]);
		}
	}
	m=ve.size();for(int i=1;i<=m;i++)e[i]=ve[i-1];
	for(int s=1;s<(1<<k);s++){
		if(!mx&&s!=(1<<k)-1)continue;
		kt=kg=0;ll sum=0;
		for(int i=1;i<=k;i++)if((s>>(i-1))&1){
			for(int j=1;j<=n;j++)
				t[++kt]=(node){n+i,j,a[i][j]};
			sum+=c[i];
		}
		sort(t+1,t+kt+1);
		int x=1,y=1;
		while(x<=m&&y<=kt){
			if(e[x].w<t[y].w)g[++kg]=e[x],x++;
			else g[++kg]=t[y],y++;
		}
		while(x<=m)g[++kg]=e[x],x++;
		while(y<=kt)g[++kg]=t[y],y++;
		for(int i=1;i<=n+k;i++)fa[i]=i,siz[i]=1;
		for(int i=1;i<=kg;i++){
			int x=g[i].x,y=g[i].y,w=g[i].w;
			if(find(x)!=find(y)){
				sum+=w;merge(x,y);
			}
		}
		ans=min(ans,sum);
	}
	printf("%lld\n",ans);
	return 0;
}