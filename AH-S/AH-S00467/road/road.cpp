#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct road{
	int u,v,w;
}a[1000005];
struct country{
	int val,weight[1005];
}con[11];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>con[i].val;
		for(int j=1;j<=n;j++){
			cin>>con[i].weight[j];
		}
	}
	int sum=0;
	for(int i=1;i<=m;i++){
		sum+=a[i].w;
	}
	cout<<sum;
	return 0;
}
