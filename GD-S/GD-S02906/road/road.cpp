#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6; 
int n,m,k;
struct edge{
	ll u,v,w;
}e[10*N+7];
int f[N+25];
ll c[12][N+7],s[15];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int find(int u){
	if(f[u]!=u) f[u]=find(f[u]);
	return f[u];
}
ll kruskal(){
	for(int i=1;i<=n;i++) f[i]=i;
	sort(e+1,e+m+1,cmp);
	int ans=0,cnt=0;
	for(int i=1;i<=m;i++){
		int x=find(e[i].u),y=find(e[i].v);
		if(x!=y){
			f[x]=y;
			ans+=e[i].w;cnt++;
			if(cnt==n-1) break;
		}
	}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int mm=m,nn=n;
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;i++){
		cin>>s[i];
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<n;j++){
			for(int l=j+1;l<=n;l++){
				e[++m]={i,j,c[i][j]+c[i][l]+s[i]};
			}
		}
	} 
	cout<<kruskal();
	return 0;
}

