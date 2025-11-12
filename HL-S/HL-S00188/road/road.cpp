#include <bits/stdc++.h>
using namespace std;
long long n,m,k,c[12],a[12][1000005];
struct Road{
	long long u,v,w;
}road[1000005];
int Link[10005][10005];
bool cmp(Road x,Road y){
	if(x.u!=y.u){
		return x.u<y.u;
	}
	else if(x.v!=y.v){
		return x.v<y.u;
	}
	else{
		return x.w<y.w;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>road[i].u>>road[i].v>>road[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	sort(road+1,road+1+n,cmp);
	for(int i=1;i<=n;i++){
		Link[road[i].u][road[i].v]=1;
	}
	long long sum=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(Link[i][j]==1){
				sum+=road[i].w;
				Link[i][j]=2;
				Link[j][i]=2;
			}
		}
	}
	cout<<sum<<"\n";
	return 0;
}