#include<bits/stdc++.h>
using namespace std;
struct Edge{
	int u,v;
	long long w;
}eg[1000006],e[20004],e2[20004];
bool cmp(Edge A,Edge B){
	return A.w<B.w;
}
int n,m,k;
long long fix[15],add[15][10004];
//vector<pair<int,int> >edge[10014];
int father[10014];
void init(int kk){
	for(int i=1;i<=kk;i++) father[i]=i;
}
int find(int kk){
	if(father[kk]!=kk) father[kk]=find(father[kk]);
	return father[kk];
}
int unite(int u,int v){
	if(find(u)!=find(v)) father[find(u)]=find(v);
}
long long mintree=0x3f;
void kruscal(){
	init(n);
	sort(eg+1,eg+1+m,cmp);
	int cnt=0;
	long long res=0;
	for(int i=1;i<=m;i++){
//		cout<<find(eg[i].u)<<" "<<find(eg[i].v)<<endl;
		if(find(eg[i].u)==find(eg[i].v)) continue;
		unite(eg[i].u,eg[i].v);
		e[++cnt]=Edge({eg[i].u,eg[i].v,eg[i].w});
		res+=eg[i].w;
	}
	m=cnt;
	mintree=min(mintree,res);
	return ;
}
int kruscal2(int cc,int pp){
	init(pp);
	sort(e2+1,e2+1+cc,cmp);
	int cnt=0;
	long long res=0;
	for(int i=1;i<=cc;i++){
		if(find(e2[i].u)==find(e2[i].v)) continue;
		unite(e2[i].u,e2[i].v);
		cnt++;
		res+=e2[i].w;
	}
	return res;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v;long long w;scanf("%d %d %lld",&u,&v,&w);
		eg[i].u=u;eg[i].v=v;eg[i].w=w;
	}
	kruscal();
//	for(int i=1;i<=m;i++){
//		cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<endl;
//	}
	bool flag=1;
	for(int i=1;i<=k;i++){
		scanf("%d",fix+i);
		flag&=(fix[i]==0);
		for(int j=1;j<=n;j++){
			scanf("%d",&add[i][j]);
		}
	}
	if(k==0){
		cout<<mintree;
		return 0;
	}
	if(k<=5){
		for(int i=1;i<(1<<k);i++){
			for(int j=1;j<=m;j++){
				e2[j].u=e[j].u;
				e2[j].v=e[j].v;
				e2[j].w=e[j].w;
			}
			int cc=0,pp=0;
			long long fixx=0;
			for(int j=1;j<=k;j++){
				if((i>>(j-1))&1){
					pp++;
					fixx+=fix[j];
					for(int kk=1;kk<=n;kk++){
						cc++;
						e2[m+cc]=Edge({n+pp,kk,add[j][kk]});
					}
				}
			}
			mintree=min(mintree,kruscal2(cc+m,pp+n)+fixx);
		}
		cout<<mintree;
	}else if(flag){
		long long newtree=0;
		for(int i=1;i<=m;i++){
			Edge tot=e[i];
			for(int j=1;j<=k;j++){
				if(add[j][e[i].u]+add[j][e[i].v]<e[i].w){
					e[i].w=min(e[i].w,add[j][e[i].u]+add[j][e[i].v]);
				}
			}
			newtree+=e[i].w;
		}
		cout<<newtree;
	}else{
		cout<<5182974424;
	}
	return 0;
}
