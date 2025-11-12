#include<bits/stdc++.h>
using namespace std;
int n,m,k,f[10100],p[20],c[12][10100],cnt=0,b[20];
long long mini=1e18;
struct edge{
	int u,v,w;
}e[1500000],e1[1500000];
int find(int x){
	if(f[x]==x)return x;
	else return f[x]=find(f[x]);
}
void mag(int x,int y){
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy)f[fx]=f[fy];
}
bool cmp(edge x,edge y){
	return x.w<y.w;
}
void dfs(int x,int t){
	if(x>k){
		long long ans=0,ppp=0;
		for(int i=1;i<=k;i++){
			if(b[i]==1){
				ans+=p[i];
				ppp++;
				for(int j=1;j<=n;j++){
					e[++cnt]={n+ppp,j,c[i][j]};
				}
				f[n+ppp]=n+ppp;
			}
		}
		sort(e+1,e+1+cnt,cmp);
		long long q=0;
		for(int i=1;i<=cnt;i++){
			int u=e[i].u,v=e[i].v;
			if(find(u)!=find(v)){
				q++;
				mag(u,v);
				ans+=e[i].w;
				if(q==n+t){
					break;
				}
			}
		}
		mini=min(mini,ans);
		cnt=m;
		for(int i=1;i<=n;i++)f[i]=i;
		for(int i=1;i<=m;i++)e[i]=e1[i];
	}else{
		b[x]=1;
		dfs(x+1,t+1);
		b[x]=0;
		dfs(x+1,t);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[++cnt]={u,v,w};
		e1[cnt]={u,v,w};
	}
	bool llf=true;
	for(int i=1;i<=k;i++){
		cin>>p[i];
		if(p[i]!=0)llf=false;
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
		}
	}
	if(llf==true){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				e[++cnt]={n+i,j,c[i][j]};
			}
			f[n+i]=n+i;
		}
		sort(e+1,e+1+cnt,cmp);
		long long q=0,ans=0;
		for(int i=1;i<=cnt;i++){
			int u=e[i].u,v=e[i].v;
			if(find(u)!=find(v)){
				q++;
				mag(u,v);
				ans+=e[i].w;
				if(q==n+k){
					break;
				}
			}
		}
		cout<<ans;
	}else{
		dfs(1,0);
		cout<<mini;
	}
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
