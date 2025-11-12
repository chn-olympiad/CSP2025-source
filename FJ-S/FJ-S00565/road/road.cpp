#include<iostream>
#include<cstdio>
using namespace std;
int n,nn,m,k,c;
int a[505],b[505];
bool vis[505];
long long ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,c;
		cin>>u>>v>>c;
		ans+=c;
	}
	cout<<ans;
	return 0;
}
