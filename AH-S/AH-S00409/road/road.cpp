/*
*/
#include<bits/stdc++.h>
#define in(a) scanf("%d",&a)
#define N 10005
#define M 1000005
#define ll long long
using namespace std;
struct edge{
	int l,r,w;
}a[M+15*N];
int n,m,k;
ll ans1=0,ans2=0;
int cnt=0;
int dist[15];
int vis[15];
bool cmp(edge x,edge y){
    return x.w<y.w;
}
int fa[N+15];
void init(){
    for(int i=1;i<=n+k;i++){
        fa[i]=i;
    }
    return ;
}
int find(int x){
    if(x==fa[x]) return x;
    return fa[x]=find(fa[x]);
}
void unite(int x,int y){
    x=find(x),y=find(y);
    if(x==y) return ;
    fa[x]=y;
    return ;
}
bool same(int x,int y){
    return find(x)==find(y);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	in(n),in(m),in(k);
	init();
	for(int i=1,u,v,w;i<=m;i++){
		in(u),in(v),in(w);
		a[++cnt]={u,v,w};
	}
	for(int i=1,u;i<=k;i++){
		in(dist[i]);
		//这个城市看作第i+n个城市
		for(int j=1,v;j<=n;j++){
			in(v);
			a[++cnt]={j,i+n,dist[i]+v};
		}
	}
	sort(a+1,a+cnt+1,cmp);
	int res=0,x=0;
	for(int i=1;i<=cnt;i++){
        edge u=a[i];
        if(!same(u.l,u.r)){
            unite(u.l,u.r);
            ans1+=u.w;
            x++;
            if(u.l>n){
                if(!vis[u.l-n]) res++;
                vis[u.l-n]++;
            }else if(u.r>n){
                if(!vis[u.r-n]) res++;
                vis[u.r-n]++;
            }
        }
        if(x==n+res-1) break;
	}
	for(int i=1;i<=k;i++){
        if(vis[i]>1) ans1-=dist[i];
	}
	init();
	x=0;
	for(int i=1;i<=cnt;i++){
        edge u=a[i];
        if(u.l>n||u.r>n) continue;
        if(!same(u.l,u.r)){
            unite(u.l,u.r);
            ans2+=u.w;
            x++;
        }
        if(x==n-1) break;
	}
	cout<<min(ans1,ans2);
    return 0;
}
