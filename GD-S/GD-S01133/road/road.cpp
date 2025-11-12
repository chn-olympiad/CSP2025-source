#include<bits/stdc++.h>
using namespace std;
const int N=2e4+10,M=1e6+10;
int n,m,k;
struct node{
	int x,y,z;
}a[M*2],e[M*2],tmp[M*2];
int fa[N],c[15],b[15][N];
long long ans;
bool cmp(node q,node p){return q.z<p.z;}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
long long Kruskal(int cnode,int m){
	int cnt=0;
	long long s=0;
	for(int i=1;i<=n+k;i++) fa[i]=i;
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;i++){
		int ax=find(a[i].x),ay=find(a[i].y);
		if(ax!=ay){
			fa[ax]=ay,s+=a[i].z;
			e[++cnt]=a[i];
			if(cnt==cnode-1) return s;
		}
	}
	return s;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
		  scanf("%d",&b[i][j]);
	}
	ans=Kruskal(n,m);
	for(int i=1;i<n;i++) a[i]=e[i],tmp[i]=e[i];
	for(int i=1;i<(1<<k);i++){
		int gs=n,ecnt=n-1;
		long long s=0;
		for(int j=1;j<n;j++) a[j]=tmp[j];
		for(int j=1;j<=k;j++)
		  if((i>>j-1)&1){
		  	gs++,s+=c[j];
		  	for(int l=1;l<=n;l++)
		  	  a[++ecnt]={n+j,l,b[j][l]};
		  }
		if(s>=ans) continue;
		ans=min(ans,s+Kruskal(gs,ecnt));
	}
	cout<<ans;
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
