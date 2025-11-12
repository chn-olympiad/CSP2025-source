#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=1e6+5;
const int N=1e4+5;
struct EDGE{
	int u,v,w,tag;
}edge[M];
int a[N];
int find(int x){
	if(a[x]==x){
		return x;
	}else return a[x]=find(a[x]);
}
int n,m,k;
int qwq[15][N],vis[15];
bool cmp(EDGE a,EDGE b){
	return a.w<b.w;
}
int cnt=0;
int tarjan(int end,int node){
	for(int i=1;i<=node;i++)a[i]=i;
	int res=0;
	for(int i=1;i<=end;i++){
		int fu=find(edge[i].u),fv=find(edge[i].v);
		if(fu==fv)continue;
		a[fu]=fv;
		res+=edge[i].w;
		if(edge[i].tag&&!vis[edge[i].tag]){
			res+=qwq[edge[i].tag][0];
			vis[edge[i].tag]=1;
		}
		cnt++;
		if(cnt==node-1)return res;
	}
	return -1;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&edge[i].u,&edge[i].v,&edge[i].w);
	}
	int tot=m;
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			scanf("%lld",&qwq[i][j]);
			if(j>=1){
				edge[++tot]=(EDGE){n+i,j,qwq[i][j],i};
			}
		}
	}
	sort(edge+1,edge+tot+1,cmp);
	int ans=tarjan(tot,n+k);
	printf("%lld",ans);
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

