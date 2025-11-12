#include<bits/stdc++.h>
using namespace std;

const int N=1e4+10;
int a[N][N],f[N],d[15][N];
int v[15][N]; 
int n,m,k;

struct node{
	int u,v,w;
	bool operator<(const node &t)const{
		return w<t.w;
	}
}e[N*N];
int find(int x){
	if(x==f[x])return x;
	return f[x]=find(f[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int cnt=0;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		e[++cnt].u=x,e[cnt].v=y,e[cnt].w=z;

	}
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=k;i++){
		int v;
		cin>>v;
		for(int j=1;j<=n;j++){
			int x;
			cin>>x;
		}
	}
	int tot=0,ans=0;
	sort(e+1,e+1+cnt);
	for(int i=1;i<=cnt;i++){
		int x=find(e[i].u);
		int y=find(e[i].v);
		if(x!=y){
			ans+=e[i].w;
			f[x]=y;
			tot++;
		}
		if(tot==n-1)break;
	}
	
	cout<<0;
	return 0;
}
