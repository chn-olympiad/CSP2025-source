#include<bits/stdc++.h>
using namespace std;
const int N=1e4+3,M=1e6+3,NN=1e3+3;
int n,m,k;
int a[NN][NN];
int c;
int d[N];
int mn[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>k;
	if(n<=1e3){
		int u,v,w;
		for(int i=1;i<=m;i++){
			cin>>u>>v>>w;
			a[u][v]=a[v][u]=w;
		}
		for(int i=1;i<=k;i++){
			cin>>c;
			for(int j=1;j<=n;j++){
				cin>>d[j];
			}
			for(int j=1;j<n;j++){
				for(int l=j+1;l<=n;l++){
					if(a[j][l]>d[j]+d[l]||a[j][l]==0)a[j][l]=a[l][j]=d[l]+d[j];
				}
			}	
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			mn[i]=INT_MAX;
			for(int j=1;j<=n;j++){
				if(i!=j&&a[i][j]<mn[i])mn[i]=a[i][j];
			}
		}
		sort(mn+1,mn+n+1);
		for(int i=1;i<n;i++){
			ans+=mn[i];
		}
		cout<<ans;
		return 0;
	}
	
	return 0;
}
