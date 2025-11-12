#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+10;
int n,m,k,ans=0,h[M],f[N],minn[N],id[N],cnt;
struct node{
	int u,v,w,nxt;
}e[M*4];
struct edge{
	int c,a[N];
}x[12];
void init(){
	for(int i=1;i<=n;i++) f[i]=i;
}
int find(int x){
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
} 
void add(int from,int to,int p){
	e[++cnt].v=to;
	e[cnt].u=from;
	e[cnt].w=p;
	e[cnt].nxt=h[from];
	h[from]=cnt;
}
bool cmp(const node a,const node b){
	return a.w<b.w;
}
int main(){
	ios::sync_with_stdio(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	init();
	memset(minn,0x3f3f3f3f,sizeof(minn));
	for(int i=1;i<=n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	sort(e+1,e+2*n+1,cmp);
	for(int i=1;i<=k;i++){
		cin>>x[i].c;
		for(int j=1;j<=n;j++) cin>>x[i].a[j];
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			minn[j]=min(minn[j],x[i].a[j]);
		}
	}
	int num=0,tot=0;
	for(int i=1;i<=2*n;i++){
		int r1=find(e[i].u),r2=find(e[i].v);
		if(r1!=r2){
			f[r1]=r2;
			num++;
			ans+=e[i].w;
			id[++tot]=i;
			if(num==n-1) break;
		}
	}
	if(k==0){
		cout<<ans<<endl;
	    return 0;
	}	
	for(int i=tot;i>=1;i--){
		if(e[i].w<minn[e[i].u]+minn[e[i].v]) continue;
		ans-=e[i].w;
		ans+=minn[e[i].u]+minn[e[i].v];
	}
	cout<<ans<<endl;
	return 0;
} 
