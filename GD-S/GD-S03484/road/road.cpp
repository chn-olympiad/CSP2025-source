#include<bits/stdc++.h>//³¬¼¶Ô´µã£¿ 
using namespace std;
const int M=5e6+50,N=1e4+140;
int n,m,k;
struct node{
	int u,v;
	long long w;
};
node e[M];
long long c[100],ans=1e13;
int a[30][N],fa[M];
bool cmp(node a,node b){
	return a.w<b.w;
}
int find(int x){
	if(fa[x]==x) return fa[x];
	else{
		fa[x]=find(fa[x]);
		return fa[x];
	}
}
void kruskal(){
	long long sum=0;
	for(int i=1;i<=m;i++){
		int x=find(e[i].u),y=find(e[i].v);
		if(x==y) continue;
		fa[x]=y;
		sum+=e[i].w;
	}
//	cout<<sum<<endl;
	ans=min(ans,sum);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	sort(e+1,e+m+1,cmp);
	kruskal();
//	cout<<ans<<endl;
	for(int i=1;i<=k+n+17;i++){
		fa[i]=i;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			m++;
			e[m].u=n+i;
			e[m].v=j;
			e[m].w=a[i][j];
		}
	}
	for(int i=1;i<=k;i++){
		m++;
		e[m].u=n+k+1;
		e[m].v=n+i;
		e[m].w=c[i];
	}
//	for(int i=1;i<=m;i++){
//		cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<endl;
//	}
	kruskal();
	cout<<ans;
	return 0;
}
