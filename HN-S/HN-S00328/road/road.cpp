#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=10005,M=1000005;
int n,m,k;
int fa[N];
struct no{
	int u,v,w;
}q[M];
int a[15][N];
int c[15];
bool vis[15];
int find(int x){
	return (fa[x]==x ? x : fa[x]=find(fa[x]));
}
bool cmp(no x,no y){
	return x.w<y.w;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>q[i].u>>q[i].v>>q[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	sort(q+1,q+m+1,cmp);
	int cnt=0;
	ll ans=0;
	for(int i=1;i<=m;i++){
		if(cnt==n-1){
			break;
		}
		int x=q[i].u,y=q[i].v,z=q[i].w;
		int fx=find(x),fy=find(y);
		if(fx!=fy){
			fa[fx]=fy;
			ans+=z;
			cnt++;
		}
	}
	cout<<ans;
	return 0;
} 
