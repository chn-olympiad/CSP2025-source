#include<bits/stdc++.h>
using namespace std;

int n,m,k,c[15],ans,d[13][10005];
int dist[10005][10005];

int r(int extra,int t,int dis[10005][10005],int rural){
	if(t==k+1){
		int x=0x3f3f3f3f;		
		for(int i=1;i<n;i++){
			x=dis[i][i+1];
			for(int j=i+1;j<=n;j++){
				x=min(dis[i][j],x);
			}
		rural+=x;
	}
	return rural;
	}
	if(t<=k){
		
		int tmp=r(extra,t+1,dis,rural);
		
		extra++;
		for(int j=1;j<=n+extra-1;j++){			
			dis[n+extra][j]=d[t][j];
			dis[j][n+extra]=d[t][j];	
		}
		for(int p=1;p<=n+extra;p++){
		for(int i=1;i<=n+extra;i++){
			for(int j=1;j<=n+extra;j++){
				dis[i][j]=min(dis[i][j],dis[i][p]+dis[p][j]);
			}
		}
	}	
	return(min(tmp,r(extra,t+1,dis,rural+c[t])));
	}
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(dist,0x3f3f,sizeof(dist));
	cin>>n>>m>>k;
	int s,e;
	for(int i=1;i<=m;i++){
		cin>>s>>e;
		cin>>dist[s][e];
		dist[e][s]=dist[s][e];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>d[i][j];
		}
	}
	for(int i=1;i<=n+k;i++){
		dist[i][i]=0;
	}
	for(int p=1;p<=n;p++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dist[i][j]=min(dist[i][j],dist[i][p]+dist[p][j]);
			}
		}
	}
	ans=r(0,1,dist,0);
	cout<<ans;
	return 0;
}
