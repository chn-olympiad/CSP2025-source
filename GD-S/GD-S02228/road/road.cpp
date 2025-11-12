#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m,k;
struct edge{
	int u,v,w;
	operator <(const edge &x) const{return w<x.w;}
}ns[1000010],ned[100010];int num;
int c[20],a[20][10010];
int fa[10020];
ll res;

int gfa(int x){
	if(x==fa[x]) return x;
	return fa[x]=gfa(fa[x]);
}

void add(const edge &x){
	if(gfa(x.u)==gfa(x.v)) return;
//	cout<<'('<<x.u<<' '<<x.v<<' '<<x.w<<')';
	fa[gfa(x.u)]=gfa(x.v);
	res+=x.w;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++) scanf("%d%d%d",&ns[i].u,&ns[i].v,&ns[i].w);
	sort(ns+1,ns+1+m);
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
	}
	ll ans=1e18; 
	for(int st=0;st<(1<<k);st++){
		res=0;
		num=0;
		for(int i=1;i<=k;i++){
			if((st&(1<<(i-1)))==0) continue;
			res+=c[i];
			for(int j=1;j<=n;j++){
				ned[++num]={n+i,j,a[i][j]};
			}
		}
		sort(ned+1,ned+1+num);
		for(int i=1;i<=n+k;i++) fa[i]=i;
		for(int i=1,j=1;i<=m||j<=num;){
//			cout<<'['<<i<<' '<<j<<']';
			if(i<=m&&(j>num||ns[i].w<ned[j].w)) add(ns[i++]);
			else add(ned[j++]); 
		}
		ans=min(ans,res);
//		cout<<res<<' '<<st<<endl;
	}
	printf("%lld\n",ans);
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
