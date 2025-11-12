#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=1e6+10;

ll edge[1010][1010],w[inf],ans;
ll n,m,k,a[inf],vis[1001][1001],fa[inf];

void floud(){
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(edge[i][j]!=0){
				for(int k=1;k<=n;k++){
					if(edge[i][k]!=0&&edge[j][k]!=0&&edge[i][j]>edge[i][k]+edge[j][k]) edge[i][j]=edge[i][k]+edge[j][k];
				}
			}
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			for(int k=j;k<=n;k++){
				if(edge[j][k]!=0&&edge[j][k]>edge[n+i][k]+edge[j][n+i]+w[i]){
					vis[j][k]=i;
					edge[j][k]=edge[n+i][k]+edge[j][n+i];
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(edge[i][j]!=0) ans+=edge[i][j]; 
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++)
		{
			if(vis[i][j]!=0) ans+=w[vis[i][j]];
		}
	}
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(ll i=1;i<=m;i++){
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		edge[x][y]=w;
		edge[y][x]=w;
	}
	for(ll i=1;i<=k;i++){
		ll ww;
		scanf("%lld",&ww);
		w[i]=ww;
		for(ll j=1;j<=n;j++) {
			ll y;
			scanf("%lld",&y);
			edge[n+i][j]=y;
			edge[j][n+i]=y;
		}
	}
	floud();
	printf("%lld\n",ans);
	return 0;
}


