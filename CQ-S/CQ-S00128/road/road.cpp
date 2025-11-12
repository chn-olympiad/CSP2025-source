#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+114,M=3e6+10;
int c[13],a[13][N],cnt=0,fa[N],ans=LONG_LONG_MAX;
struct node{
	int x,y,z;
}e[M],py[M];
bool cmp(node c,node d){
	return c.z<d.z;
}
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,u,v,w;
	cin>>n>>m>>k;
	while(m--){
		cin>>u>>v>>w;
		py[++cnt]={u,v,w};
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<(1<<k);i++){
		int co=i,tot=0,sum=0,bt=0;		
		for(int j=1;j<=cnt;j++) e[++bt]=py[j];
		while(co){
			tot++;
			if(co&1){
				sum+=c[tot];
				for(int j=1;j<=n;j++) e[++bt]={tot+n,j,a[tot][j]},fa[tot+n]=tot+n;
			}
			co>>=1;
		}
		for(int j=1;j<=n;j++) fa[j]=j;
		sort(e+1,e+bt+1,cmp);
		for(int j=1;j<=bt;j++){
			int tx=find(e[j].x),ty=find(e[j].y);
			if(tx==ty) continue;
			fa[tx]=ty;
			sum+=e[j].z;
		}
		ans=min(sum,ans);
		memset(e,0,sizeof(e));
		memset(fa,0,sizeof(fa));
	}
	cout<<ans<<'\n';
	return 0;
}

