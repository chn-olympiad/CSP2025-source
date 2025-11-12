#include<bits/stdc++.h>
using namespace std;
long long n,m,k,t,fa[10010],c[50],p[50][10010],ct[11],cu[11];
long long r[50],x,xr,xw,ans=1^15,cnt,xv,xu,u,v,w,s;
bool ting;
struct node{
	int u,v,w;
}edge[1000010],cedge[11][1000010];
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
long long kruscal(){
	for(int i=0;i<=k;i++)r[i]=1;
	for(int i=1;i<=n;i++)fa[i]=i;
	x=0,xr=1;
	cnt=0,s=0;
	while(s<n-1){
		xw=edge[r[0]].w;
		x=0,xr=r[0];
		for(int i=1;i<=k;i++){
			if(cu[i]==0)continue;
			while(r[i]<=ct[i]&&find(cedge[i][r[i]].u)==find(cedge[i][r[i]].v))r[i]++;
			if(r[i]<=ct[i]&&cedge[i][r[i]].w<xw){
				xw=cedge[i][r[i]].w;
				x=i,xr=r[i];
			}
		}
		r[x]++;
		if(x==0)xu=edge[xr].u,xv=edge[xr].v;
		else xu=cedge[x][xr].u,xv=cedge[x][xr].v;
		if(find(xu)!=find(xv)){
			fa[xu]=xv;
			cnt+=xw;
			s++;
		}
	}
	return cnt;
}
void dfs(int ki,int s){
	if(ki>k){
		return;
	}
	cu[ki]=1;
	ans=min(kruscal()+s+c[ki],ans);
	dfs(ki+1,s+c[ki]);
	cu[ki]=0;
	ans=min(kruscal()+s,ans);
	dfs(ki+1,s);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&u,&v,&w);
		edge[i].u=u,edge[i].v=v,edge[i].w=w;
	}
	sort(edge+1,edge+1+m,cmp);
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&p[i][j]);
		}
		t=0;
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				cedge[i][++t].u=j,cedge[i][t].v=k,cedge[i][t].w=p[i][j]+p[i][k];
			}
		}
		sort(cedge[i]+1,cedge[i]+1+t,cmp);
		ct[i]=t;
	}
	ans=min(kruscal(),ans);
	dfs(1,0);
	cout<<ans;
	return 0;
}
