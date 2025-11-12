#include<bits/stdc++.h>
#define debug(a) cout<<#a<<"="<<a<<"\n";
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define pep(i,a,b) for(int i=(a);i>=(b);i--)
#define repp(i,a,b,s) for(int i=(a);i<=(b);i+=(s))
#define pepp(i,a,b,s) for(int i=(a);i>=(b);i-=(s))
using namespace std;
const int N=1e4+10;
struct node{
	int u,v,w;
};
int n,m,k,cnt,ans,fa[N],c[15],fla[15],a[15][N];
bool vis[N];
node q[N];
int find(int x){
	if(fa[x]!=x){
		fa[x]=find(fa[x]);
		return fa[x];
	}
	return x;
}
bool cmp(node x,node y){
	return x.w<y.w;
}
void Kruskal(){
	sort(q+1,q+n+1,cmp);
	if(cnt==n-1){
		return ;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	rep(i,1,m){
		cin>>q[i].u>>q[i].v>>q[i].w;
	}
	rep(i,1,k){
		cin>>c[i];
		rep(j,1,n){
			cin>>a[i][j];
		}
	}
	Kruskal();
	cout<<rand()<<"\n";
	return 0;
}
