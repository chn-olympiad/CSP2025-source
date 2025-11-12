#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e6+10,N=1e4+11;
int n,m,k;
int c[20];
int a[20][N];
int fa[N],fat[N];
int cnt;
struct edge{
	int u,v,w;
	bool operator < (const edge &x)const{
		return w>x.w; 
	} 
}E1[M],E[N][1100];
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int work(int S){
	for(int i=1;i<=n+k;i++)fa[i]=i;
	priority_queue<edge>q;
	int res=0,cntt=0,la=0;
	for(int i=0;i<k;i++){
		if((S>>i)&1){
			res+=c[i+1];
			la=i;
		}
	}
	int x=1;
	while(E[x][S-(1<<la)].u){
		q.push(E[x][S-(1<<la)]);
		x++;
	}
	for(int i=1;i<=n;i++)q.push({n+la+1,i,a[la+1][i]});
	while(!q.empty()){
		edge EE=q.top();
		q.pop();
		int ex=find(EE.u),ey=find(EE.v);
		if(ex==ey)continue;
		res+=EE.w;
		E[++cntt][S]=EE;
		fa[ex]=ey;
	}
	return res;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++)fa[i]=i;
	int x,y,z;
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&x,&y,&z);
		E1[i].u=x;
		E1[i].v=y;
		E1[i].w=z;
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
		}
	}
	sort(E1+1,E1+m+1,cmp);
	int ans=0;
	for(int i=1;i<=m;i++){
		int ex=find(E1[i].u),ey=find(E1[i].v);
		if(ex==ey)continue;
		fa[ex]=ey;
		ans+=E1[i].w;
		E[++cnt][0]=E1[i];
	}	
	for(int S=1;S<1<<k;S++){
		int res=work(S);
		ans=min(ans,res);
	}
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
