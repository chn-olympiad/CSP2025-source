#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
int ans;
int g[10005][10005];
int fa[10005];
int q[15][10005],r[15],minn[10005];
int vis[10005][10005];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	scanf("%lld%lld%lld",&n,&m,&k);
	
	for(int i=1;i<=m;i++){
		int a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		vis[a][b]=1;
		g[a][b]=c;
		g[b][a]=c;
	}
	for(int i=1;i<=k;i++){
		int a;
		scanf("%lld",&a);
		r[i]=a;
		for(int j=1;j<=n;j++){
			int b;
			scanf("%lld",&b);
			q[i][j]=b;
		}
	}
	
	
	fa[1]=1;
	for(int i=1;i<n;i++){
		int mn=1e9,mnn=1e9;
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			if(vis[i][j]){
				if(g[i][j]<mnn){
					mnn=g[i][j];
					mn=j;
				}
			}
		}
		
		for(int j=1;i<=k,j<=n;j++){
			if(i==fa[i]) continue;
			int tt=r[i]+q[i][j];
			//cout<<tt<<" ";
			if(tt<mnn){
				mnn=tt;
				mn=j;
			}
		}
		
		fa[mn]=i;
		//cout<<i<<" "<<mn<<" "<<mnn<<endl;
		ans+=mnn;
    }
    cout<<ans;
	return 0;
}