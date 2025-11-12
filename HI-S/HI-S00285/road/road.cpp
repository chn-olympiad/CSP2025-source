#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans,cnt;
long long c[15],c2[15][10005],f[10005],p[10005],a[1005][1005];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		long long u=0,v=0,w=0;
		scanf("%lld%lld%lld",&u,&v,&w);
		a[u][v]=w;
		a[v][u]=w;
	}
	int flag=0; 
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		if(c[i]!=0) flag=1;
		for(int j=1;j<=n;j++){
			scanf("lld",&c2[i][j]);
			if(c2[i][j]!=0) flag=1;
		}
	}
	if(flag==0){
		cout<<0;
		return 0;
	}
	return 0;
}
