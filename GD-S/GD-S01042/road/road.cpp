#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e6+7,N=1e4+6;
int n,m,k,c[30],a[30][N],fa[M],siz[M],ret=1e18;
struct sttside{
	int u,v,w;
}side[M],nside[M];
struct sttside2{
	int u,v,w,id;
}cside[M];
int cntns,cntcs;
bool cmp(sttside a,sttside b){
	return a.w<b.w;
}
bool cmp2(sttside2 a,sttside2 b){
	return a.w<b.w;
}
int find(int x){
	if(x==fa[x]){return x;}
	int tmp=find(fa[x]);
	fa[x]=tmp;
	siz[x]=siz[tmp];
	return tmp;
}
void merge(int u,int v){
	u=find(u),v=find(v);
	if(siz[u]<siz[v])swap(u,v);
	siz[u]+=siz[v];
	fa[v]=u;
}
void init(){
	for(int i=1;i<=n+15;i++)fa[i]=i,siz[i]=1;
}
void kruskal(){
	sort(side+1,side+1+m,cmp);
	init();
	for(int i=1;i<=m;i++){
		int u=side[i].u,v=side[i].v,w=side[i].w;
		if(find(u)!=find(v)){ 
			merge(u,v);
			nside[++cntns]={u,v,w};
		}
	}
}
signed main(){
	ios::sync_with_stdio(false); 
	cin.tie(0),cout.tie(0);
		freopen("road.in","r",stdin);
		freopen("road.out","w",stdout);

	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>side[i].u>>side[i].v>>side[i].w;
	}
		for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			cside[++cntcs]={i+n,j,a[i][j],i};
			
		}
	}

	sort(cside+1,cside+1+cntcs,cmp2);
	kruskal();
	for(int i=0;i<(1<<k);i++){
		init();
		int ans=0,l1=1,l2=1;
		for(int j=1;j<=k;j++){
			if((1<<(j-1))&i)ans+=c[j];
		}
		while(l1<=cntns&&l2<=cntcs){
			if(nside[l1].w<cside[l2].w||l2==cntcs+1){
				int u=nside[l1].u,v=nside[l1].v,w=nside[l1].w;
				if(find(u)!=find(v)){
					merge(u,v);
					ans+=w;
				}
				l1++;
			}
			else{
				if((1<<(cside[l2].id-1))&i){
					int u=cside[l2].u,v=cside[l2].v,w=cside[l2].w;
					if(find(u)!=find(v)){
						merge(u,v);
						ans+=w;
					}
				}
				l2++;
			}
		}
		ret=min(ret,ans);
	}
	cout<<ret;
	return 0;
}
