#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=1e9+5;
const int N=1e4+5,M=1e5+5;
int n,m,k,x,y,z,h;
ll ans;
int fa[N],cnt[N];
bool f[N];
int g[N][N],c[N],a[N][N];
/*int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}*/
void prim(int i){
	if(h==n) return;
	for(int j=1;j<=n;j++){
		if(/*g[i][j]!=INF && */!f[j]){
			cnt[j]=min(cnt[j],g[i][j]);
		}
	}
	//for(int j=1;j<=n;j++) cout<<j<<' '<<cnt[j]<<endl;
	int o=INF,p;
	for(int j=2;j<=n;j++){
		if(!f[j] && cnt[j]<o){
			o=cnt[j];
			p=j;
		}
	}
	h++;
	f[p]=1;
	ans+=o;
	//cout<<i<<' '<<p<<' '<<ans<<endl;
	prim(p);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(g,INF,sizeof(g));
	memset(a,INF,sizeof(a));
	memset(cnt,INF,sizeof(cnt));
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		g[x][y]=g[y][x]=min(z,g[x][y]);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				g[j][k]=g[k][j]=min(g[j][k],c[i]+a[i][j]+a[i][k]);
			}
		}
	}
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<i<<' '<<j<<' '<<g[i][j]<<endl;
		}
	}*/
	cnt[1]=0;f[1]=1;h=1;
	prim(1);
	cout<<ans;
	return 0;
}
