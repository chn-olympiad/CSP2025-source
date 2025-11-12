# include <bits/stdc++.h>
const int N=10014;
const int M=110014;
using namespace std;
int n,m,k,cnt_old,fu,fv;
int fa[N];
int c[18]; 
bool book[N];
long long ans;
struct edge{
	int u,v,w;
	bool new_road;
}e[M];
bool cmp(edge p,edge q){
	if(p.w!=q.w){
		return p.w<q.w; 
	}
	if(p.new_road!=q.new_road){
		return q.new_road;
	}
	return true;
}
int ff(int u){
	if(u!=fa[u]){
		fa[u]=ff(fa[u]);
	}
	return fa[u];
}
void kruskal(){
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=m;i++){
		fu=ff(e[i].u);
		fv=ff(e[i].v);
		if(fu==fv){
			continue;
		}
		fa[fu]=fv;
		ans+=e[i].w;
		if(e[i].new_road){
			fu=e[i].u-n;
			ans-=c[fu];
			if(!book[e[i].u]){
				ans+=c[fu];
			}
			
		}
		if(!book[e[i].u]){
			book[e[i].u]=true;
			if(e[i].u<=n){
				cnt_old++;
			}
		}if(!book[e[i].v]){
			book[e[i].v]=true;
			cnt_old++;
		}
		if(cnt_old==n){
			return;
		}
	}
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
		e[i].new_road=false;
	}
	for(int i=1;i<=k;i++){
		fa[n+i]=n+i;
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&e[++m].w);
			e[m].w+=c[i];
			e[m].v=j;
			e[m].u=n+i;
			e[m].new_road=true;
		}
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	kruskal();
	cout<<ans;
	return 0;
}