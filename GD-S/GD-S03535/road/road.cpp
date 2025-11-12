#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int N=1e4+5,M=1e6+5;
int n,m,k,c[M],a[M][N],ans,b[N];
struct lll{
	int u,v,w;
};
bool cmp(lll d.w,lll b,w){
	if(d.w<=b.w) return 1;
	else return 0;
}
lll d[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&d[i].u,&d[i].v,d[i].w);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	} 
	if(k==0){
		sort(d+1,d+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(b[d[i].u]==1) continue;
			if(b[d[i].v]==1) continue;
			b[d[i].u]=1,b[d[i].v]=1;
			ans+=d[i].w;
		}
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
