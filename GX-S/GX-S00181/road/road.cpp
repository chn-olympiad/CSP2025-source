#include<bits/stdc++.h>
using namespace std;
unsigned int n,m,k,mapsu[10005][10005],road[10005],visited,nowaday,minipri,mtogo,ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			mapsu[i][j]=1000000005;
		}
	}
	for(int i=1,u,v;i<=m;i++){
		cin >> u >> v;
		cin >> mapsu[u][v];
		mapsu[v][u] = mapsu[u][v];
	}
	for(int j=1,p,a[10005];j<=k;j++){
		cin >> p;
		for(int i=1;i<=m;i++){
			cin >> a[i];
		}
		for(int i=1;i<=n;i++){
			for(int b=1;b<=n;b++){
				mapsu[i][b] = min(int(mapsu[i][b]), (a[i]+a[b]+p));
			}
		}
	}
	nowaday=1;road[1]=1;
	for(int u=1;visited<=n;u++){
		minipri=1000000002;mtogo=0;
		for(int i=1;i<=n;i++){
			if(mapsu[nowaday][i]<minipri){
				mtogo=i;
				minipri=mapsu[nowaday][i];
			}
		}
		if(mtogo == 0){
			u-=2;
			nowaday=road[u+1];
			continue;
		}
		for(int i=1;i<=n;i++){
			mapsu[nowaday][i] = mapsu[i][nowaday] = 1000000005;
			mapsu[mtogo][i] = mapsu[i][mtogo] = 1000000005;
		}
		road[u]=mtogo;
		nowaday = mtogo;
		ans+=minipri;
		visited++;
	}
	cout << ans;
}
//0?
