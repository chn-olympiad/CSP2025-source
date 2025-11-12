#include<bits/stdc++.h>
#define gc getchar
using namespace std;
typedef long long ll;
const int N = 1e4+3,M = 1e6+3,K = 12;
inline int re(){
	int x=0;bool f=0;char c=gc();
	for(;c<'0'||c>'9';c=gc())f=c=='-';
	for(;c>='0'&&c<='9';c=gc())x=x*10-48+c;
	return f?-x:x;
}
int hd[N],tot;
struct Edge{int u,v,w;}ed[M];
bool cmp(Edge x,Edge y){return x.w<y.w;}
struct Star{int v,lst;ll w;}e[N<<1];
inline void add(int x,int y,ll z){e[++tot]={y,hd[x],z},hd[x]=tot;}

ll a[K][N],ans,c[K],sum;
int n,m,k,fa[N];

int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}

void kruskal(){
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(ed+1,ed+m+1,cmp);
	for(int i=1,cnt=0;i<=m;i++){
		int u=ed[i].u,v=ed[i].v,w=ed[i].w;
		u=find(u),v=find(v);
		if(u==v)continue;
		add(ed[i].u,ed[i].v,w),
		add(ed[i].v,ed[i].u,w);
		fa[u]=v,sum+=w,cnt++;
		if(cnt==n-1)break;
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=re(),m=re(),k=re();
	for(int i=1,x,y,z;i<=m;i++){
		x=re(),y=re(),z=re();
		ed[i]={x,y,z};
	}
	for(int i=1;i<=k;i++){
		c[i]=re();
		for(int j=1;j<=n;j++)a[i][j]=re();
	}
	kruskal();
	ans=sum;
	
	cout<<ans;
	
	/*
4 5 0
1 2 1
1 3 1
2 4 1
3 4 1
2 3 8
	*/
	return 0; 
} 
