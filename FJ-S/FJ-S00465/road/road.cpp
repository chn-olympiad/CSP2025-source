#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int u[100005],v[100005],w[100005];
int c[15],a[15][100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	
	return 0;
}
//	= ======
//		=
//
//
//
// orz orz (:o)RZ @rz Orz oRz orZ OrZ ORz oRZ 
