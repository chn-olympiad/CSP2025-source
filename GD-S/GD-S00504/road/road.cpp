#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n,m,k;
int c[N],a[11][N];
int dis[N],lar[N];
bool vis[N];
bool A=1;
int aa=INT_MAX;
int nr=1,cc=0;
long long ans=LONG_LONG_MAX;
vector<pair<int,int>>mp[N];
void dij(int s){
	cc=0; bool ff=0;
	for(int i=0;i<=n;i++){
		dis[i]=0x3f3f3f3f;
		vis[i]=0;
		lar[i]=0;
	}
	dis[s]=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> a;
	a.push(make_pair(dis[s],s));
	while(!a.empty()){
		int u=a.top().second;
		a.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=0;i<mp[u].size();i++){
			int v=mp[u][i].first,w=mp[u][i].second;
			ff=0;
			if(v>n){
				v-=n;
				ff=1;
			}
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				lar[v]=w;
				if(ff) cc++;
				a.push(make_pair(dis[v],v));
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		mp[u].push_back(make_pair(v,w));
		mp[v].push_back(make_pair(u,w));
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		aa=min(aa,c[i]);
		if(c[i]!=0)A=0;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]!=0)A=0;
//			mp[j].push_back(make_pair(n+nr,a[i][j]));
//			mp[n+nr].push_back(make_pair(j,a[i][j]));
		}
//		nr++;
	}
	if(A&&k!=0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=k;i++){
		for(int l=1;l<n;l++){
			for(int r=l+1;r<=n;r++){
				mp[l].push_back(make_pair(r+n,a[k][l]+a[k][r]));
				mp[r].push_back(make_pair(l+n,a[k][l]+a[k][r]));
			}
		}
	}
	for(int i=1;i<=n;i++){
		dij(i);
		long long cnt=0;
		for(int j=1;j<=n;j++){
			cnt+=lar[j];
		}
		if(cc!=0)cnt+=aa;
		ans=min(ans,cnt);
	}
	cout<<ans;
	return 0;
}

