#include<bits/stdc++.h>
using namespace std;
const int M=1005,N=1e6+5;
int n,m,k,minn=INT_MAX,f[M][M],c[N],a[M][M],sum,th[M][M],mind;
bool vis[M][M],F[M][M],V[M][M],FF;
void dfs(int s,int e,int ans,int dep){
	if(s==e){
		if(ans<minn||(ans==minn&&dep>mind)){
			mind=dep;
			minn=ans;
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					th[i][j]=F[i][j];
				}
			}
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(F[s][i])continue;
		if(s!=i){
			if(vis[s][i]){
				F[i][s]=F[s][i]=1;
				dfs(i,e,ans,dep);
				F[i][s]=F[s][i]=0;
			}
			else {
				if(V[i][s]){
					F[s][i]=F[i][s]=1;
				    dfs(i,e,ans+f[s][i],dep+1);
				    F[s][i]=F[i][s]=0;
			    }
			}
		}
	}
}
int main () {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		f[u][v]=w;
		f[v][u]=w;
		V[u][v]=1;
		V[v][u]=1;
		if(w==0)vis[u][v]=vis[v][u]=1;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
		for(int j=1;j<=n;j++){
			for(int l=j+1;l<=n;l++){
				if(f[j][l]==0)f[j][l]=f[l][j]=INT_MAX;
				if(f[j][l]>c[i]+a[i][j]+a[i][l]){
					f[j][l]=f[l][j]=c[i]+a[i][j]+a[i][l];
					c[i]=0;
					V[j][l]=V[l][j]=1;
				}
			}
		}
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(vis[i][j])continue;
			for(int ii=1;ii<=n;ii++){
				for(int jj=1;jj<=n;jj++){
					F[ii][jj]=0;
					th[ii][jj]=0;
				}
			}
			minn=INT_MAX;
			mind=0;
			dfs(i,j,0,0);
			if(minn==0)continue;
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					if(th[i][j]&&!vis[i][j]){
						vis[i][j]=vis[j][i]=1;
						sum+=f[i][j];
					}
				}
			}
		}
	}
	cout<<sum;
    return 0;
}
