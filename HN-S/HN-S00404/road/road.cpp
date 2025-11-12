#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
const int M=1e4+5;

struct node{
	int u,v,w;
};

bool cmp(node x,node y){
	return x.w<y.w;
}

int n,m,k;
int c[N];
int f[M][M];
int fa[N];
int ans=0;
node a[N];
int g[N];
int remain;

int find(int x){
	if (x==fa[x]){
		return x;
	}
	fa[x]=find(fa[x]);
	return fa[x];
}

bool merge(int x,int y){
	int xx=find(x);
	int yy=find(y);
	if (xx==yy){
		return false;
	}
	fa[yy]=xx;
	return true;
}

void solve(){
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	sort(a+1,a+m+1,cmp);
	for (int i=1;i<=k;i++){
		cin>>c[i];
		for (int j=1;j<=n;j++){
			cin>>f[i][j];
		}
	}
	for (int i=1;i<=n;i++){
		fa[i]=i;
	}
	if (k==0){
		for (int i=1;i<=m;i++){
			if (merge(a[i].u,a[i].v)==1){
				ans+=a[i].w;
			}
		}
	}
	for (int i=1;i<=m;i++){
		memset(g,0,sizeof(g));
		int minn=1e18;
		remain=-1;
		for (int j=1;j<=k;j++){
			if (g[j]>=1){
				if (minn>f[j][a[i].u]+f[j][a[i].v]){
					minn=f[j][a[i].u]+f[j][a[i].v];
					remain=j;
				}
			}
			else {
				if (minn>c[j]+f[j][a[i].u]+f[j][a[i].v]){
					minn=c[j]+f[j][a[i].u]+f[j][a[i].v];
					remain=j;
				}
			}
		}
		if (remain!=-1){
			g[remain]++;	
		}

		int minnn=min(a[i].w,minn);
		if (merge(a[i].u,a[i].v)==1){
			ans+=minnn;
		}
	}
	cout<<ans<<"\n";
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	solve();
	return 0;
}
