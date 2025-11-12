#include <bits/stdc++.h>
using namespace std;
const int N=20000,M=2000000;
int n,m,k,fa[N],tot;
int pd[15][N],c[15];
long long ans;
struct Node{
	int x,y,w;
}gr[M],xg[M],by[M];
bool cmp(Node a,Node b){
	return a.w<b.w;
}
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=m;i++) cin>>gr[i].x>>gr[i].y>>gr[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>pd[i][j];
	}
	sort(gr+1,gr+m+1,cmp);
	for(int i=1;i<=m;i++){
		int x=gr[i].x,y=gr[i].y;
		int fx=find(x),fy=find(y);
		if(fx!=fy){
			xg[++tot]={x,y,gr[i].w};
			ans+=gr[i].w;
			fa[fx]=fy;
		}
	}
	for(int i=1;i<(1<<k);i++){
		for(int j=1;j<=n+k;j++) fa[j]=j;
		int cnt=0,bs=0,xjr=__builtin_popcount(i);
		long long sum=0;
		for(int j=1;j<=tot;j++) by[++cnt]=xg[j];
		for(int j=1;j<=k;j++){
			if((i>>(j-1))&1){
				sum+=c[j];
				for(int l=1;l<=n;l++) by[++cnt]={j+n,l,pd[j][l]};
			}
		}
		if(sum>=ans) continue;
		sort(by+1,by+cnt+1,cmp);
//		for(int j=1;j<=cnt;j++) cout<<by[j].x<<' '<<by[j].y<<endl;
		for(int j=1;j<=cnt;j++){
			int x=by[j].x,y=by[j].y;
			int fx=find(x),fy=find(y);
			if(fx!=fy){
				sum+=by[j].w;
				if(sum>=ans) break;
				bs++;
				fa[fx]=fy;
				if(bs==n+xjr-1) break;
			}
		}
//		cout<<sum<<endl;
		ans=min(ans,sum);
	}
	cout<<ans;
	return 0;
}

