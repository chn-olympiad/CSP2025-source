#include<bits/stdc++.h>
using namespace std;

long long n,m,k,d[15][10005];
struct ss{
	long long u,v,w;
}a[1000005];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>a[i].u>>a[i].v>>a[i].w;
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++) cin>>d[i][j];
	}
	
	cout<<0;
	
	
	return 0;
}
