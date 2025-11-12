#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll p[1005][1005],w,c[11],t[1005],dis[1005],ans;
int n,m,k,u,v;
bool vis[1005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			p[i][j]=-1;
		}
	}
	for(int i=1; i<=m; i++) {
		scanf("%d%d%lld",&u,&v,&w);
		p[u][v]=p[v][u]=w;
	}
	for(int i=1; i<=k; i++) {
		scanf("%lld",c+i);
		for(int j=1; j<=n; j++) {
			scanf("%lld",t+j);
		}
		for(int j=1; j<=n; j++) {
			for(int q=j+1; q<=n; q++) {
				if(p[j][q]==-1) p[j][q]=p[q][j]=t[j]+t[q]+c[i];
				else p[j][q]=p[q][j]=min(p[j][q],t[j]+t[q]+c[i]);
			}
		}
	}
	int now=1,cnt=1,ss=1000000000,x=0;
	vis[now]=1;
	for(int i=1; i<=n; i++) dis[i]=1000000000;
	while(cnt<=n) {
		ss=1000000000;
		vis[now]=1;
		for(int i=1;i<=n;i++) {
			if(vis[i]||i==now) continue;
			if(p[now][i]<dis[i]){
				dis[i]=p[now][i];
			    if(dis[i]<ss){
			    	ss=dis[i];
			    	x=i;
				}
			}
		}
		now=x;
		cnt++;
	}
	for(int i=2;i<=n;i++) ans+=dis[i];
	cout<<ans;
	return 0;
}
