#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e4+5;
const int M=2e6+5;
int n,m,k;
struct edge{
	int u,v,w;
}e[M],nw[M];
int c[15];
int g[15][N];
int fa[N];
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
bool cmp(edge i,edge j){
	return i.w<j.w;
}
int solve1(){
	int ans=0;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	sort(e+1,e+m+1,cmp);
	int lt=0;
	for(int i=1;i<=m;i++){
		int x=find(e[i].u);
		int y=find(e[i].v);
		int z=e[i].w;
		if(x==y) continue;
		
		//cout<<e[i].u<<" "<<e[i].v<<" "<<z<<'\n';
		
		ans+=z;
		lt++;
		fa[x]=y;
		if(lt==n-1) break;
	}
	return ans;
}
int solve(int num,int tot){
	int dot_n=n+num,lt=0;
	int ans=0;
	for(int i=1;i<=dot_n;i++){
		fa[i]=i;
	}
	int edge_m=m+tot;
	for(int i=tot+1;i<=edge_m;i++){
		nw[i]=e[i-tot];
	}
	sort(nw+1,nw+edge_m+1,cmp);
	for(int i=1;i<=edge_m;i++){
		int x=find(nw[i].u);
		int y=find(nw[i].v);
		int z=nw[i].w;
		if(x==y) continue;
		ans+=z;
		lt++;
		fa[x]=y;
		if(lt==dot_n-1) break;
	}
	return ans;
}
int tot;
int rdy(int s){
	int num=0,res=0;
	tot=0;
	for(int i=0;i<k;i++){
		if((s>>i) &1 ){
			num++;
			res+=c[i+1];
			for(int j=1;j<=n;j++){
				nw[++tot]={(num+n),j,g[i+1][j]};
			}
		}
	}
	return res+solve(num,tot);
}
void xpigeon(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	if(k==0){
		cout<<solve1()<<'\n';
		return ;
	}
	int ans=solve1();
	
	//cout<<ans<<'\n';
	
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>g[i][j];
		}
	}
	for(int s=1;s<(1<<k);s++){
		ans=min(ans,rdy(s));
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	xpigeon();
	return 0;
}
