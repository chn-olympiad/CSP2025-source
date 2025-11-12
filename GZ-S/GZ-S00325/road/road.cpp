//GZ-S00325 贵阳市第一中学 王梓竣 
#include <bits/stdc++.h>
using namespace std;
#define int long long
struct Edge{
	int u;
	int v;
	int rk;
	int k;
}edge[2000005],tmp[2000005];
int a,b,c,n,m,ans,tot,T,k;
int head[200005];
int fa[200005];
int cost[15];
int find(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
}
int check(int x,int y){
	return find(x)==find(y);
}
void merge(int x,int y){
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy){
		fa[fx]=fy;
	}
}
void add(int u,int v,int rk,int id){
	edge[++tot]={u,v,rk,id};
}
bool cmp(Edge a,Edge b){
	return a.rk<b.rk;
}
int kruskal(int sta){
	int sum=0;
	for(int i=1;i<=k;i++){
		if(sta&(1<<(i-1))){
			sum+=cost[i];
		}
	}
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	for(int i=1;i<=tot;i++){
		if(sta&edge[i].k || edge[i].k==0){
			if(!check(edge[i].u,edge[i].v)){
				//cout<<sta<<" "<<(sta&edge[i].k) <<" "<<edge[i].u<<" "<<edge[i].v<<" "<<edge[i].rk<<" "<<edge[i].k<<"\n";
				merge(edge[i].u,edge[i].v);
				sum+=edge[i].rk;
			}
		}
	}
	return sum;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	ans=10000000000000000;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>a>>b>>c;
		tmp[i]={a,b,c,0};
	}
	sort(tmp+1,tmp+1+m,cmp);
	for(int i=1;i<=m;i++){
		if(!check(tmp[i].u,tmp[i].v)){
			merge(tmp[i].u,tmp[i].v);
			add(tmp[i].u,tmp[i].v,tmp[i].rk,0);
		}
	}
	for(int i=1;i<=k;i++){
		cin>>cost[i];
		for(int j=1;j<=n;j++){
			cin>>a;
			add(n+i,j,a,(1<<(i-1)));
		}
	}
	sort(edge+1,edge+1+tot,cmp);
	int sta=0;
	while(sta<(1<<k)){
		ans=min(ans,kruskal(sta));
		sta++;
	}
	cout<<ans;
	return 0; 
}
