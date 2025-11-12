#include<bits/stdc++.h>
using namespace std;
struct node {
	int v,w,type;
};
bool vis[10005];
int dis[10005];
bool zhen[11];
int a[11];
vector<node> road[10005];
int main() {
	for (int i=0; i<10005; i++) {
		dis[i]=INT_MAX;
	}
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0; i<m; i++) {
		int u,v,w;
		cin>>u>>v>>w;
		node f= {v,w,0};
		road[u].push_back(f);
		f.v=u;
		road[v].push_back(f);
	}
//    cout<<"cityok\n";
	for(int i=1; i<=k; i++) {
		cin>>a[i];
		int f[n+1];
		for(int j=1; j<=n; j++) cin>>f[i];

		for(int j=1; j<=n; j++)
			for(int k=j+1; k<=n; k++) {
				int fu=(a[i]+f[j]+f[k]);
				node f= {j,fu,i};
				road[k].push_back(f);
				f.v=k;
				road[j].push_back(f);
			}
//            cout<<"countryside ok\n";
	}
	dis[1]=0;
	int ans=0;
	for (int p=0; p<n; p++) {
		int mini=0;
		for(int i=1; i<=n; i++) {
			if(dis[i]<dis[mini]&&!vis[i]) {
				mini=i;
			}
		}

		vis[mini]=1;
		ans+=dis[mini];
//		cout<<p<<":"<<mini<<"  "<<ans<<endl;
		for(node f:road[mini]) {
			dis[f.v]=min(dis[f.v],f.w);
		}
	}
	cout<<ans;

	return 0;
}
