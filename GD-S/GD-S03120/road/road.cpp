#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int u,v,w;
int c[10010],ans;
int mapa[10010][10010],l[10010],xh[10010];
bool city[10010];
bool cmp(int x,int y){
	return l[x]<l[y];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(mapa,0x3f,sizeof(mapa));
	memset(l,0x3f,sizeof(l));
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&u,&v,&w);
		mapa[u][v]=w;
		mapa[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			scanf("%d",&c[j]);
		}
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				mapa[j][k]=min(mapa[j][k],c[j]+c[k]+c[0]);
				mapa[k][j]=min(mapa[k][j],c[j]+c[k]+c[0]);
			}
		}
	}
	city[1]=1;
	l[1]=0;
//	for(int i=1;i<=n;i++){
//		if(city[i]==0)l[i]=mapa[i][1];
//	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) xh[j]=j;
		sort(xh+1,xh+1+n,cmp);
		ans+=l[xh[1]];
		city[xh[1]]=1;
		l[xh[1]]=0x3f;
		for(int j=1;j<=n;j++){
			if(city[j]==0){
				l[j]=min(l[j],mapa[j][xh[1]]);
			}
		}
	}
	cout<<ans;

	return 0;
}

