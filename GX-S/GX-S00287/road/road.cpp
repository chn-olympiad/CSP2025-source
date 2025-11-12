#include <bits/stdc++.h>
using namespace std;
const int MAXM=1e6+5,MAXN=1e4+5;
int fa[MAXM];
void init_dsu(int size){
	for(int i=1;i<=size;i++) fa[i]=i;
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	fa[find(x)]=find(y);
}
struct edge{
	int u,v,w;
	bool operator <(const edge x)const{
		return w<x.w;
	}
}e[MAXM];
int n,m,k;
int dd[MAXN][MAXN]={};
int ks[11][MAXN];
int dq[11],cb[11]={};
int last[MAXN][MAXN]={};
bool cbxz[11]={};
void kruskal(){
	int sr=0,ans=0;
	sort(e+1,e+m+1);
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v;
		if(find(u)!=find(v)){
			merge(u,v);
			sr+=1,ans+=e[i].w;
			if(sr==n-1){
				cout <<ans <<endl;
				return;
			}
		}
	}
}
void kruskal_optmized(){
	int sr=0,ans=0;
	sort(e+1,e+m+1);
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v;
		if(find(u)!=find(v)){
			merge(u,v);
			sr+=1,ans+=e[i].w;
			dd[e[i].u][e[i].v]=e[i].w;
			dd[e[i].v][e[i].u]=e[i].w;
			if(sr==n-1){
				break;
			}
		}
	}
	for(int i=1;i<=k;i++){
		int newans=ans;
		for(int j=1;j<=n-1;j++){
			for(int k=j+1;k<=n;k++){
				if(dd[j][k]>ks[i][j]+ks[i][k]&&last[j][k]==0){
					newans+=ks[i][j]+ks[i][k];
					newans-=dd[j][k];
					dd[j][k]=ks[i][j]+ks[i][k];
					last[j][k]=i;
					cb[i]++;
					cbxz[i]=true;
				}else if(dd[j][k]>ks[i][j]+ks[i][k]&&last[j][k]!=0){
					newans+=ks[i][j]+ks[i][k];
					newans-=dd[j][k];
					dd[j][k]=ks[i][j]+ks[i][k];
					cb[last[j][k]]--;
					last[j][k]=i;
					cb[i]++;
				}
			}
		}
		ans=min(ans,newans+dq[i]);
	}
	for(int i=1;i<=k;i++) if(cb[i]<=0&&cbxz[i]) ans-=dq[i];
	cout <<ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >>n >>m >>k;
	for(int i=1;i<=m;i++){
		cin >>e[i].u >>e[i].v >>e[i].w;
	}
	for(int i=1;i<=k;i++){
		cin >>dq[i];
		for(int j=1;j<=n;j++) cin >>ks[i][j];
	}
	init_dsu(m);
	if(k==0) kruskal();
	else kruskal_optmized();
	return 0;
}
