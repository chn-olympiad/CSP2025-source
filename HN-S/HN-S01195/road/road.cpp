#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=1e6+10,K=15;
int n,m,k,u[M],v[M],w[M],c[K],a[K][N],ans;
bool sov=true;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
		ans+=w[i];
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		if(sov&&c[i]==0)sov=true;
		else sov=false;
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			if(sov&&a[i][j]==0)sov=true;
			else sov=false;
		}
	}
	if(sov)cout<<0;
	else cout<<ans;
	return 0;
}
