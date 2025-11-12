#include<bits/stdc++.h>
using namespace std;
struct e {
	int t,w,nex;
} edge[1000001];
int head[1000001];
int cnt=0;
void add(int s,int t,int w) {
	edge[++cnt].t=t;
	edge[cnt].w=w;
	edge[cnt].nex=head[s];
	head[s]=cnt;
}
int dis[1000001];
int book[1000001];
int xd[15][50003];
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0; i<=n; i++) {
		dis[i]=1e9;
	}
	for(int i=1; i<=m; i++) {
		int s,t,w;
		cin>>s>>t>>w;
		add(s,t,w);
		add(t,s,w);
	}

	for(int i=1; i<=k; i++) {
		int w;
		cin>>w;
		for(int j=1; j<=n; j++) {
			int t;
			cin>>t;
			xd[i][j]=t;
		}
	}
	if(k==0) {
		int ans=0;
		dis[1]=0;
		book[1]=1;
		for(int i=head[1]; i; i=edge[i].nex) {
			dis[edge[i].t]=edge[i].w;
		}
		for(int i=1; i<n; i++) {
			int mix=0;
			for(int j=1; j<=n; j++) {
				if(!book[j]&&dis[mix]>dis[j]) {
					mix=j;
				}
			}
			ans+=dis[mix];
			book[mix]=1;
			for(int i=head[mix]; i; i=edge[i].nex) {
				if(!book[i]&&dis[edge[i].t]>edge[i].w) {
					dis[edge[i].t]=edge[i].w;
				}
			}
		}
		cout<<ans;
	}else{
		int ans=0;
		dis[1]=0;
		book[1]=1;
		for(int i=head[1]; i; i=edge[i].nex) {
			dis[edge[i].t]=edge[i].w;
		}
		int jp=1e9;
		for(int i=1; i<=k; i++) {
			for(int j=1;j<=n;j++){
				dis[j]=min(dis[j],xd[i][j]);
				jp=min(jp,xd[i][1]);
			}
		}
		for(int i=1; i<n; i++) {
			int mix=0;
			for(int j=1; j<=n; j++) {
				if(!book[j]&&dis[mix]>dis[j]) {
					mix=j;
				}
			}
			ans+=dis[mix];
			book[mix]=1;
			for(int i=head[mix]; i; i=edge[i].nex) {
				if(!book[i]&&dis[edge[i].t]>edge[i].w) {
					dis[edge[i].t]=edge[i].w;
				}
			}
		}
		cout<<ans+jp;
	}
	
}
