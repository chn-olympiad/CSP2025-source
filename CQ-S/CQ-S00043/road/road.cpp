#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5;
struct edge{
	int u,v,w;
};

bool cmp(edge x,edge y){
	return x.w<y.w;
}

int n,m,k,dp[N],a[15][N],c[15],fa[N],lcnt,ans;
edge e[10*M];

int find(int x){
	if(fa[x]==x){
		return fa[x];
	}else{
		return fa[x]=find(fa[x]);
	}
}

void merge(int x,int y){
	fa[find(x)]=fa[find(y)];
}

void kruscarl(){
	for(int i=1;i<n;i++){
		int fx=find(e[i].u),fy=find(e[i].v);
		if(fx!=fy){
			merge(fx,fy);
			ans+=e[i].w;
		}
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1,x,y,z;i<=m;i++){
		cin>>x>>y>>z;
//		dp[i]=z;
		e[++lcnt]={x,y,z};
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
		for(int j=1;j<=n;j++){
			for(int k1=1;k1<j;k1++){
				e[++lcnt]={j,k1,a[i][j]+a[i][k1]+c[i]};
			}
		}
	}
//	if(k!=0){
//		cout<<0;
//		return 0;
//	}
	sort(e+1,e+lcnt+1,cmp);
	kruscarl();
	cout<<ans;
	return 0;
}

