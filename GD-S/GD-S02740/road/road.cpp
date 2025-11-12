#include<bits/stdc++.h>
using namespace std;
const int N=1e4+50,M=1e6+5;
int n,m,k;long long ans;
int fa[N],h[N],p;
void init(){for(int i=1;i<N;i++)fa[i]=i,h[i]=0;}
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void merge(int x,int y){
	x=find(x),y=find(y);
	if(h[x]<h[y])swap(x,y);
	fa[y]=x,h[x]+=(h[x]==h[y]);
}
int u[M],v[M],w[M],id[M];
bool cmp(int i,int j){return w[i]<w[j];}
int g[M],tot;
int c[15];
struct edge{
	int w,id;
	bool friend operator<(edge i,edge j){return i.w<j.w;}
}e[15][N];
int dgt[15],cur[15],cnt;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//system("fc road3.ans road.out");return 0;
	//freopen("road3.in","r",stdin);freopen("road.out","w",stdout);
	freopen("road.in","r",stdin);freopen("road.out","w",stdout);
	cin>>n>>m>>k;//cerr<<n<<'\n';
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];id[i]=i;
	}
	sort(id+1,id+m+1,cmp);init();
	p=n;
	for(int i=1;i<=m&&p>1;i++){
		int j=id[i];
		if(find(u[j])!=find(v[j]))p--,merge(u[j],v[j]),ans+=w[j],g[++tot]=j;
	}
	//cerr<<'%'<<0<<' '<<ans<<'\n';
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>e[i][j].w,e[i][j].id=j;
		sort(e[i]+1,e[i]+n+1);
		//for(int j=1;j<=n;j++)cerr<<'^'<<i<<' '<<e[i][j].id<<' '<<e[i][j].w<<'\n';
	}
	for(int i=1;i<(1<<k);i++){
		long long sum=0;
		cnt=0;
		for(int j=0;j<k;j++)if((i>>j)&1)dgt[++cnt]=j,sum+=c[j];
		for(int j=1;j<=cnt+1;j++)cur[j]=0;
		init();p=n+cnt;
		while(p>1){
			int f,uu,vv,ww=(1<<30);
			for(int x=1;x<=cnt+1;x++){
				if(x==cnt+1){
					if(cur[x]==n-1)continue;
					//cerr<<'$'<<u[g[cur[x]+1]]<<' '<<v[g[cur[x]+1]]<<' '<<w[g[cur[x]+1]]<<'\n';
					if(w[g[cur[x]+1]]<ww)uu=u[g[cur[x]+1]],vv=v[g[cur[x]+1]],ww=w[g[cur[x]+1]],f=x;
				}else{
					if(cur[x]==n)continue;
					//cerr<<'$'<<dgt[x]<<' '<<e[dgt[x]][cur[x]+1].id<<' '<<e[dgt[x]][cur[x]+1].w<<'\n';
					if(e[dgt[x]][cur[x]+1].w<ww)uu=n+1+dgt[x],vv=e[dgt[x]][cur[x]+1].id,ww=e[dgt[x]][cur[x]+1].w,f=x;
				}
			}
			cur[f]++;
			if(find(uu)==find(vv))continue;
			//cerr<<'#'<<uu<<' '<<vv<<' '<<ww<<'\n';
			merge(uu,vv),sum+=ww,p--;
		}
		ans=min(ans,sum);
		//cerr<<'%'<<i<<' '<<sum<<'\n';
	}
	cout<<ans<<'\n';
} 
