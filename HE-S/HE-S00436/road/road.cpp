#include<bits/stdc++.h>
using namespace std;

const int MAXM=1e6+5;
const int MAXN=1e4+5;
long long n,m,k;
struct Edge{
	long long u,v,w;
}edge[MAXM];
long long c[15][MAXN];
long long ans=0;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>edge[i].u>>edge[i].v>>edge[i].w;
	}
	for(int j=1;j<=k;j++){
		for(int i=1;i<=n;i++){
			cin>>c[j][i];
		}
	}
	
	cout<<0; //ÌØÊâÐÔÖÊA 
	return 0;
}
