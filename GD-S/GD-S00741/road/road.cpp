#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 10025
int ans;
int n,m,k;
struct edge{
	int u,v,w,tp;
	bool operator<(const edge b)const{return w<b.w;}
}e[1000005],d[N];
int c[15],cnt;
int f[N],g[N];
int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
void mer(int x,int y){
	x=find(x),y=find(y);
	if(g[x]<g[y])swap(x,y);
	g[x]+=g[y];
	f[y]=x;
}
void clr(){
	for(int i=1;i<=n+k;i++)f[i]=i,g[i]=1;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		e[i]={u,v,w,-1};
	}
	sort(e+1,e+1+m);
	clr();
	for(int i=1,u,v,w;i<=m;i++){
		u=e[i].u,v=e[i].v,w=e[i].w;
		if(find(u)==find(v))continue;
		ans+=w;
		d[++cnt]=e[i];
		mer(u,v);
	}
//	cout<<ans<<endl;
	for(int i=1;i<=cnt;i++){
		e[i]=d[i];
	}
	m=cnt;
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=1,w;j<=n;j++){
			cin>>w;
			e[++m]={n+i+1,j,w,i};
		}
	}
	sort(e+1,e+1+m);
	for(int o=1;o<(1<<k);o++){
		int tot=0;
		for(int i=0;i<k;i++)tot+=((o>>i)&1)*c[i];
		clr();
		for(int i=1,u,v,w,tp;i<=m;i++){
			u=e[i].u,v=e[i].v,w=e[i].w,tp=e[i].tp;
			if((~tp)&&((o>>tp)&1)==0)continue;
			if(find(u)==find(v))continue;
			tot+=w;
			mer(u,v);
//		if(o==1)cout<<u<<' '<<v<<' '<<w<<endl;
		}
		ans=min(ans,tot);
	}
	cout<<ans;
	return 0;
} 
