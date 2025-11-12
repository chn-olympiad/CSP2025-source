#include<bits/stdc++.h>
using namespace std;
const int kMaxN=1e4+5,kMaxK=12,kMaxM=1e6+5,kMaxN2=1e3+4;
int n,m,k,top;
long long c[kMaxK],a[kMaxK][kMaxN],maxc=-1,ans,dis[kMaxN2][kMaxN2];
int d[kMaxN],sz[kMaxN];
struct B{
	int u,v;
	long long w;
}z[kMaxM];
bool cmp(B i,B j){
	return i.w<j.w;
}
int F(int x){
	return d[x]==x?x:d[x]=F(d[x]);
}
void S1(){
	for(int i=1;i<=n;i++) d[i]=i,sz[i]=1;
	sort(z+1,z+top+1,cmp);
	for(int i=1;i<=top;i++){
		int xx=F(z[i].u),yy=F(z[i].v);
		if(xx!=yy){
			d[xx]=yy,ans+=z[i].w,sz[yy]+=sz[xx];
		}
		if(sz[F(1)]==n){
			break;
		}
	}
	cout<<ans;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>z[i].u>>z[i].v>>z[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		maxc=max(maxc,c[i]);
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(maxc==0){
		fill(dis[0],dis[n+1],1e18);
		for(int i=1;i<=m;i++){
			dis[z[i].u][z[i].v]=min(dis[z[i].u][z[i].v],z[i].w);
			dis[z[i].v][z[i].u]=dis[z[i].u][z[i].v];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				long long minn=1e18;
				for(int o=1;o<=k;o++){
					minn=min(a[o][i]+a[o][j],minn);
				}
				dis[i][j]=min(dis[i][j],minn);
				dis[j][i]=dis[i][j];
			}
		}	
		top=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				z[++top]={i,j,dis[i][j]};
			}
		}
	}
	if(maxc==-1) top=m;
	S1();
    return 0;
}

