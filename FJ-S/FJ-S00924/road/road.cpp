#include<bits/stdc++.h>
using namespace std;
struct Road{
	int u,v,w;
}road[1000241];
int n,m,k,cntr[41],vis[10241][10241],ans;
bool cmp(Road bzo,Road bze){
	return bzo.w<bze.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int aa,bb,cc;
		cin>>aa>>bb>>cc;
		road[i].u=min(aa,bb);
		road[i].v=max(aa,bb);
		road[i].w=cc;
		cntr[aa]++;cntr[bb]++;
		ans+=cc;
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			int yh;
			cin>>yh;
		}
	}
	sort(road+1,road+m+1,cmp);
	int i=m;
	while(m>=n&&i>=0){
		if(cntr[road[i].u]>=2&&cntr[road[i].v]>=2){
			ans-=road[i].w;
			m--;
			cntr[road[i].u]--;cntr[road[i].v]--;
		}
		i--;
	}
	cout<<ans;
	return 0;
}
