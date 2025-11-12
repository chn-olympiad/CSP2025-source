#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+50,M=2e6+10;//?
const ll inf=1e16;

struct edge{
	int u,v; ll w;
}edges[M],cedges[M];
int c[20],a[20][N],n,m,k;

int fa[N];
int find(int x){
	return ((x==fa[x])?x:(fa[x]=find(fa[x])));
}

bool cmp(edge x,edge y){
	return x.w<y.w;
}
ll kr(){
	for(int i=1;i<=n;++i) fa[i]=i;
	sort(edges+1,edges+m+1,cmp);
	ll ans=0;
	for(int i=1,j=1,u,v,w,fu,fv;i<=m&&j<=n-1;++i){
		u=edges[i].u; v=edges[i].v; w=edges[i].w;
		fu=find(u); fv=find(v);
//		cout<<i<<":"<<fu<<","<<fv<<"\n";
		if(fu==fv) continue;
		fa[fu]=fv;
		ans+=w;
	}
	return ans;
}
//void add(int u,int v,int w){
//	
//}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1,u,v,w;i<=m;++i){
		scanf("%d %d %d",&u,&v,&w);
		edges[i]={u,v,w};
	}
	
	bool f=1;
	for(int i=1;i<=k;++i){
		scanf("%d",&c[i]);
		if(c[i]!=0) f=0;
		bool f2=0;
		for(int j=1;j<=n;++j){
			scanf("%d",&a[i][j]);
			if(a[i][j]==0) f2=1;
		}
		f&=f2;
	}
	if(f){
		for(int i=1,u;i<=k;++i){
			for(int j=1;j<=n;++j){
				if(a[i][j]==0){
					u=j; break;
				}
			}
			for(int v=1;v<=n;++v){
				if(v==u) continue;
				edges[++m]={u,v,a[i][v]};
			}
		}
		cout<<kr();
	}else if(k==0){
		cout<<kr();
	}else{
		ll ans=inf;
		int cn=n,cm=m;
		memcpy(cedges,edges,sizeof(edges));
		ll suma=0;
		for(int s=0;s<(1<<k);++s){
			n=cn; m=cm; suma=0;
			memcpy(edges,cedges,sizeof(edges));
			for(int i=1;i<=k;++i){
				if(((1<<(i-1))&s)==(1<<(i-1))){
					suma+=c[i];
					++n;
					for(int v=1;v<=cn;++v){
						edges[++m]={n,v,a[i][v]};
					}
				}
			}
			ans=min(ans,suma+kr());
//			cout<<s<<":"<<suma<<" "<<kr()<<" "<<ans<<"\n";
		}
		cout<<ans;
	}
	
	return 0;
} 
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4


*/
/*
6 8 0
1 2 1
2 4 1
3 4 1
1 3 1
3 6 1
4 6 1
2 5 2
4 5 2
 
*/ 
/*
rp++
love pinkrabbit forever 

*/ 
