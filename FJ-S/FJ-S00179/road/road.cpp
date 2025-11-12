#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[1000005],v[1000005];
long long w[1000005],c[15],a[15][1000005],b[10005][10005],p,q,l;
int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		cin>>u[i]>>v[i]>>w[i];
		b[u[i]][v[i]]=w[i];
		b[v[i]][u[i]]=w[i];
	}
	for(int i=1;i<=k;++i){
		cin>>c[i];
		for(int j=1;j<=m;++j)
			cin>>a[i][j];
	}
	sort(w+1,w+1+n);
	for(int i=1;i<=n-1;++i)
		l+=w[i];
	cout<<l; 
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
}
