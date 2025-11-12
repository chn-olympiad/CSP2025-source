#include<bits/stdc++.h>
using namespace std;
const int N=1000001;
int n,m,k,ans;
int u[N],v[N],w[N],a[11][N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int minn=INT_MAX;
	int id=0;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(u[j]==0&&v[j]==0) continue;
			if(u[j]==i||v[j]==i){
				minn=min(minn,w[j]);
				if(w[j]<=minn) id=j;
			}
		}
		int c=u[id];
		int r=v[id];
		ans+=w[id];
		w[id]=0;
		for(int j=1;j<=m;j++){
			if(u[j]==c||u[j]==r) u[j]=0;
			if(v[j]==c||v[j]==r) v[j]=0;
		}
		minn=INT_MAX;
	}
	cout<<ans;
	return 0;
}
