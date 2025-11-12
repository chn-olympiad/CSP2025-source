#include<bits/stdc++.h>
using namespace std;
int n,m,k;
vector<pair<int,int> > G[1005];
int ww[100005];
int main(){
    freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		ww[i]=w;
	}
	int gg;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			cin>>gg;
		}
	}
	long long sum=0;
	sort(ww+1,ww+1+m);
	for(int i=1;i<=n+1;i++){
		sum+=ww[i];
	}
	cout<<sum;
	return 0;
}
