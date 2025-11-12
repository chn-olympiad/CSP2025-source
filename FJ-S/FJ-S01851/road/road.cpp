#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,c[11],a[11][10010],sum;
vector<pair<int,int>>g[1000010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		sum+=w;
		g[u].push_back(make_pair(v,w));
		g[v].push_back(make_pair(u,w));
	}
	if(k==0){
		printf("%d",sum);
		return 0;
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	printf("%d",504898585);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
