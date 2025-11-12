#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+5;
int n,m,k,ans;

struct edge{
	int nxt,t,len;
}road[N*2];

int cnt,head[N],a[N],dis[N],p[N],o[N];

void add(int u,int v,int z){
	cnt++;
	road[cnt].t=v;
	road[cnt].nxt=head[u];
	road[cnt].len=z;
	head[u]=cnt;
}

void spfa(){
	for(int i=1;i<=n;++i){
		dis[i]=9999999999;
	}
	p[1]=1;
	for(int i=head[1];i;i=road[i].nxt){
		int v=road[i].t;
		dis[v]=min(road[i].len,dis[v]);
	}
	for(int i=1;i<=n;++i){
		int dist=9999999999;
		int node=0;
		for(int i=1;i<=n;++i){
			if(p[i]==0&&dist>dis[i]){
				
				node=i;
				dist=dis[i];
				//cout<<node<<'\n';
			}
		}
		
		p[node]=1;
		if(o[node]){
			dist+=o[node];
			o[node]=0;
		}
		
		for(int i=head[node];i;i=road[i].nxt){
			int v=road[i].t;
			dis[v]=min(dis[v],road[i].len);
		}
		ans+=dist;
	}
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=m+1;i<=m+k;++i){
		cin>>o[i];
		for(int j=1;j<=n;++j){
			cin>>a[j];
		}
		for(int i=1;i<=n-1;++i){
		    for(int j=i+1;j<=n;++j){
			    add(i,j,a[i]+a[j]);
			    o[cnt]=o[i];
			    add(j,i,a[i]+a[j]);
			    o[cnt]=o[i];
		    }
	    }
	    o[i]=0;
	}
	o[0]=0;
	spfa();
	cout<<ans+1;
	return 0;
}
