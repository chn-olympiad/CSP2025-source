#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+20;
int n,m,a[15][N],u,v,fa[N],w,g[100],cnt,ans,c[N],k,h[1001][1001];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
struct as{
	int x,y,w;
}b[200*N],d[200*N];
inline bool cmp(as a,as b){
	return a.w<b.w;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		b[i].x=u;b[i].y=v;b[i].w=w;
	}int f=0;
	for(int j=1;j<=n;j++){
		for(int k=j+1;k<=n;k++){
			h[j][k]=1e11;
		}
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0)f=1;
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				h[j][k]=min(h[j][k],a[i][j]+a[i][k]);
			}
		}
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	if(f==0){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				b[++m].w=h[i][j];
				b[m].x=i;b[m].y=j;
			}
		}
		stable_sort(b+1,b+m+1,cmp);
		for(int i=1;i<=m;i++){
			int zx=find(b[i].x),zy=find(b[i].y);
			if(zx!=zy){
				ans+=b[i].w;
				fa[zx]=zy;
			}
		}
		cout<<ans;
	}
	else{
		sort(b+1,b+m+1,cmp);
		for(int i=1;i<=m;i++){
			int zx=find(b[i].x),zy=find(b[i].y);
			if(zx!=zy){
				ans+=b[i].w;
				fa[zx]=zy;
			}
		}
		cout<<ans;
	}
	return 0;
}

