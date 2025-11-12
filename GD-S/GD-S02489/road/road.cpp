#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4+5,MAXM=1e6+5,MAXK=1e1+5;
int n,m,k,c[MAXK],a[MAXK][MAXN],fa[MAXN];
struct node{
	int u,v,w;
};
vector<node>g;
bool cmp(node x,node y){
	return x.w<y.w;
} 
int find(int k){
	if(fa[k]==k)return k;
	return fa[k]=find(fa[k]);
}
void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx!=fy)fa[fx]=fy;
}
int solve(){
	int cnt=0,ans=0;
	sort(g.begin(),g.end(),cmp);
	for(int i=0;i<m;i++){
		int fu=find(g[i].u),fv=find(g[i].v);
		if(fu!=fv){
			merge(fu,fv);
			cnt++;
			ans+=g[i].w;
			if(cnt==n-1)return ans;
		}
	}
	return -1;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		g.push_back({u,v,w});
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	if(k==0){
		cout<<solve();
		return 0;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]==0){
				for(int k=1;k<=n;k++)if(j!=k)g.push_back({j,k,a[i][k]});
			}
		}
	}
	cout<<solve();
	return 0;
}
