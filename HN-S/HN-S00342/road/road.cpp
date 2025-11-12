#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=2e6+50;
int n,m,k,fa[N],cnt=0;
struct edge{
	int u,v,w;
}a[M];
int x,y,z,m1,ans=0;
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void build(edge x){
	int fx=find(x.u),fy=find(x.v);
	if(fx!=fy){
		fa[fx]=fy;
		ans+=x.w;
		cnt++;
	}
	return;
}
bool cmp(edge p,edge q){
	return p.w<q.w;
}
bool check(){
	for(int i=1;i<=n+k;i++)
		if(fa[i]==i)return false;
	return true;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m1>>k;
	for(int i=1;i<=m1;i++){
		cin>>x>>y>>z;
		a[++m]={x,y,z};
		a[++m]={y,x,z};
	}
	for(int j=1;j<=k;j++){
		cin>>x;
		for(int i=1;i<=n;i++){
			cin>>x;
			a[++m]={n+j,i,x};
			a[++m]={i,n+j,x};
		}
	}
	for(int i=1;i<=n+k;i++)fa[i]=i;
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;i++){
		build(a[i]);
		if(cnt==n+k-1)break;
	}cout<<ans<"\n";
	return 0;
} 
/*
4 4 1
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
*/
