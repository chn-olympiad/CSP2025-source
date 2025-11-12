#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e4+10;
const int maxm=1e6+10;
struct edge{
	int u,v,w;
	bool operator<(const edge &o)const{
		return w<o.w;
		return u<o.u;
		return v<o.v;
	}
}e[maxm];
int fa[maxn];

int n,m,k;
void init(){
	for(int i=1;i<=n;i++)fa[i]=i;
}
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int a=find(x),b=find(y);
	if(a==b)return ;
	else{
		fa[a]=b;
	}
}
ll kruskal(){
	ll ret=0;
	sort(e+1,e+m+1);
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(find(u)==find(v))continue;
		//cout<<find(u)<<" "<<find(v)<<endl;
		merge(u,v);
		ret+=w;
	}
	return ret;
}
int c[15];
int a[15][maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int tmp=m;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}

	if(k==0){
		init();
		cout<<kruskal();
	}
	else{
	
		for(int i=1;i<=k;i++){
			cin>>c[i];
			for(int j=1;j<=n;j++){
				cin>>a[i][j];

				e[++m].u=i;
				e[m].v=j;
				e[m].w=a[i][j];
				a[j][i]=a[i][j];
				for(int l=tmp;l>=1;l--){
					if(e[l].u!=j&&e[l].v!=j)continue;
					else if(e[l].u==j){
						if(a[i][j]+a[i][e[l].v]<e[l].w){
							e[++m].w=c[i]+a[i][j]+a[i][e[l].v];
						}
					}
					else{
						if(a[i][j]+a[i][e[l].u]<e[l].w){
							e[++m].w=c[i]+a[i][j]+a[i][e[l].u];
						}
					}
					//cout<<e[m].u<<" "<<e[m].v<<" "<<e[m].w<<endl;
				}
			}
		}
		init();
		cout<<kruskal();
		
		//cout<<0;
	}
	
	
	return 0;
}
