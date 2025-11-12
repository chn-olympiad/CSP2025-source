//GZ-S00036 六盘水市第二十四中学 冉哲睿
#include<bits/stdc++.h>
using namespace std;
long long minn=INT_MAX,n,m,k,c[11],a[11][10001],w[10001][10001];
vector<int>g[1000001];
bool b[1000001];
void f(int j,long long q,int s){
	if(s==n){
		minn=min(minn,q);cout<<minn;
		return;
	}
	b[j]=1;
	for(int i=0;i<g[j].size();i++){
		int l=g[j][i];
		if(b[l]==0){
			f(l,q+w[j][l],s+1);
		}
	}b[j]=0;
}
int main(){
	freopen("road3.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
		scanf("%d",&w[u][v]);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
		for(int j=1;j<n;j++){
			for(int l=j+1;l<=n;l++){
				if(a[i][j]+a[i][l]<w[j][l]){
					w[j][l]=a[i][j]+a[i][l];
				}
			}
		}
	}f(1,0,0);
	cout<<minn;
	return 0;
}
