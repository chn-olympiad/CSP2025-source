#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int NR=2e5+5,MR=1e6+5;
int n,m,k,sz[NR<<1];
int u,v,w,C[NR],d[11][NR],toe=0;
ll ans=1e18;
int fa[NR<<1],tot=0;
struct Edge{
	int u,v,w;
};
Edge b[MR],R[NR<<1],E[NR<<4];
bool cmp(Edge a,Edge b){
	return a.w<b.w;
}
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
void Merge(int x,int y){
	if(x!=y)
	sz[x]<sz[y]?(fa[x]=y,sz[y]+=sz[x]):(fa[y]=x,sz[x]+=sz[y]);	
}
void Output(Edge T){
	cout<<T.u<<"->"<<T.v<<':'<<T.w<<'\n';
}
void Cha(){
	for(int i=1;i<=toe;i++)
		Output(E[i]);
	cout<<"-----\n";
	for(int i=1;i<=tot;i++)
		Output(R[i]);

}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i,sz[i]=1;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		b[i]=(Edge){u,v,w};
	}
	for(int i=1;i<=k;i++){
		cin>>C[i];
		for(int j=1;j<=n;j++){
			cin>>d[i][j];
			E[++toe]={n+i,j,d[i][j]};
		}
	}
	sort(E+1,E+toe+1,cmp);
	sort(b+1,b+m+1,cmp);
	for(int i=1;i<=m;i++){
		int _u=find(b[i].u),_v=find(b[i].v);
		if(_u!=_v){
			Merge(_u,_v);
			R[++tot]=(Edge){_u,_v,b[i].w};
		}	
	}
	for(int i=0;i<(1<<k);i++){
		int pr=1,pe=1,num=0;
		ll sum=0;
		for(int j=1;j<=n+k;j++)fa[j]=j,sz[j]=1;
		for(int j=1;j<=k;j++){
			if(i&(1<<j-1)){
				++num;
				sum+=C[j];
			}
		}
		int cnt=0;	
		for(int j=1;cnt<num+n-1;j++){
			while(pe<=toe&&(!(i&(1<<E[pe].u-n-1)))){
				++pe;
			}
			if(pe>toe||(pr<=tot&&R[pr].w<E[pe].w)){
			//	cout<<cnt<<','<<find(R[pr].u)<<'+'<<find(R[pr].v)<<'\n';
				if(find(R[pr].u)!=find(R[pr].v)){
					Merge(find(R[pr].u),find(R[pr].v));
					sum+=1ll*R[pr].w;
					++cnt;
				}
				++pr;
			}else{
				if(find(E[pe].u)!=find(E[pe].v)){
					Merge(find(E[pe].u),find(E[pe].v));
					sum+=1ll*E[pe].w;
					++cnt;
				}
				++pe;
			}
			if(cnt>=num+n-1)break;
		}
		ans=min(ans,sum);
	}
	cout<<ans;
	return 0;
}