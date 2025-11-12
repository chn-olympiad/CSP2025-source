#include<bits/stdc++.h>
using namespace std;
long long dis[10005],ans,minn,minx;
int n,m,k,u,v,w;
vector<pair<long long,long long> > vec[10005];
bool bl[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0){
		for(int i=1;i<=m;i++){
			cin>>u>>v>>w;
			vec[u].push_back({v,w});
			vec[v].push_back({u,w});
		}
		for(int i=1;i<=n;i++){
			dis[i]=LLONG_MAX;
		}
		bl[1]=true;
		for(int i=0;i<vec[1].size();i++){
			dis[vec[1][i].first]=vec[1][i].second;
		}
		for(int j=2;j<=n;j++){
			minn=LLONG_MAX;
			for(int i=2;i<=n;i++){
				if((!bl[i])&&dis[i]<minn){
					minn=dis[i];
					minx=i;
				}
			}
			bl[minx]=true;
			ans+=minn;
			for(int i=0;i<vec[minx].size();i++){
				dis[vec[minx][i].first]=min(dis[vec[minx][i].first],vec[minx][i].second);
			}
		}
		cout<<ans;
		return 0;
	}
	else{
		cout<<0;
		return 0;
	}
}
