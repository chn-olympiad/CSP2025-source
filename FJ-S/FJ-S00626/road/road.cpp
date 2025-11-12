#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k,w[10005][15];
ll a[10005][10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++){
		ll u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		a[u][v]=w;
		a[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			scanf("%lld",&w[j][i]);
			
		}
	}
	ll mx=-1,ans=0;
	for(int i=1;i<=n;i++){
		ll mn;
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			mn=a[i][j];
			for(int l=1;l<=k;l++){
				mn=min(mn,w[i][l]+w[j][l]+w[0][l]);
			}
		}
		mx=max(mx,mn);
		ans+=mn;
	}
	printf("%lld",ans-mx);
	return 0;
} 
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
