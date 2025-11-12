#include<bits/stdc++.h>
#define int long long
using namespace std;
struct edge{
	int u,v,w,val;
}e[1000005],emin[10005];
struct node{
	int to,w;
};
vector<node> g[10005];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int fa[10005],c[20][10005],minx[20],moreminx[20];
bool use[20];
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
int ans,n,m,k,cnt;
void kruskal(){
	for(int i=1;i<=m;i++){
		int fx=find(e[i].u),fy=find(e[i].v);
		if(fx!=fy){
			ans+=e[i].w;
			fa[fx]=fy;
			//g[e[i].u].push_back((node){e[i].v,e[i].w});
			//g[e[i].v].push_back((node){e[i].u,e[i].w});
			emin[++cnt].u=e[i].u,emin[cnt].v=e[i].v,emin[cnt].w=e[i].w;
		}
		if(cnt==n-1) return ;
	}
	return ;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	if(n==1){
		puts("0");
		return 0;
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i][0];
		minx[i]=1e18,moreminx[i]=1e18;
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
			if(c[i][j]<minx[i]) moreminx[i]=minx[i],minx[i]=c[i][j];
			else moreminx[i]=min(moreminx[i],c[i][j]);
		}
	}
	sort(e+1,e+1+m,cmp);
	kruskal();
	if(k==0){
		cout<<ans<<endl;
		return 0;
	}
	int tag=ans;
	int tot=0;
	for(int tmp=0;tmp<(1<<k);tmp++){
		tot=0;
		for(int i=0;i<k;i++){
			if(tmp&(1<<i)) use[i+1]=1,tot+=c[i+1][0];
			else use[i+1]=0;
		}
		for(int i=1;i<=cnt;i++){
			int res=1e18;
			int u=emin[i].u,v=emin[i].v,w=emin[i].w,case1=0,case2=0;
			for(int j=1;j<=k;j++){
				if(!use[j]) continue;
				if(c[j][u]==minx[j]) case1=c[j][u]+moreminx[j]-w;
				else case1=c[j][u]+minx[j]-w;
				if(c[j][v]==minx[j]) case2=c[j][v]+moreminx[j]-w;
				else case2=c[j][v]+minx[j]-w;
				res=min(res,min(case1,case2));
			}	
			if(res<0) tot=tot+res;
		}
		
		ans=min(ans,tag+tot);
	}
	cout<<ans<<endl;
}
