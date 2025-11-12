#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node{
	int u,v,w;
}a[1000005];
int b[1000005];
int c[15],s[15][1000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>b[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>s[i][j];
		}
	}
	int cost=0;
	sort(b+1,b+n+1);
	for(int i=1;i<=n-1;i++){
		cost+=b[i];
	}	
	cout<<cost;
	return 0;
}

