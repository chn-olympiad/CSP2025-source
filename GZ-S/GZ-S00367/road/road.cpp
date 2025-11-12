//GZ-S00367 贵阳市第一中学 罗浚瑜 
#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
const int N=1e4+20,M=1e6+20;
int n,m,k,res;
int c[15],cnt;
bool vis[M],book[N];
struct Edg{
	int u,v,w;
}g[M];
bool cmp(Edg a,Edg b){
	return a.w>b.w;
}
bool pd(){
	for(int i=1;i<=n;i++){
		if(!book[i]) return 0;
	}
	return 1;
}
void dfs(int u){
	for(int i=1;i<=cnt;i++){
		if(g[i].u==u && !book[g[i].v] && !vis[i]){
			int nx=g[i].v;
			book[nx]=1;
			dfs(nx);
		}
		if(g[i].v==u && !book[g[i].u] && !vis[i]){
			int nx=g[i].u;
			book[nx]=1;
			dfs(nx);
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,x,y,z;i<=m;i++){
		cin>>g[i].u>>g[i].v>>g[i].w;
		res+=g[i].w;
	}
	cnt=n;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>g[++cnt].w;
			g[cnt].u=n+i;g[cnt].v=j;
			res+=g[cnt].w;
		}
		res+=c[i];
	}
	sort(g+1,g+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		vis[i]=1;
		memset(book,0,sizeof book);
		book[1]=1;
		dfs(1);
		if(pd()){
			if(g[i].u>n) res-=c[i-n];
			res-=g[i].w;
		}
		else vis[i]=0;
	}
	cout<<res;
	return 0;
}
