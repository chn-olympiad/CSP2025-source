#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+10,M=1e6+10;
bool f[N];
struct node{
	int u,v,w;
}l[M];
int a[12],c[12][N];
int n,m,k;
ll ans=0;
bool cmp(node p,node q){
	return p.w<q.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>l[i].u>>l[i].v>>l[i].w;
	for(int i=1;i<=k;i++){
		cin>>a[i];
		for(int j=1;j<=n;j++) cin>>c[i][j];
	}
	sort(l+1,l+1+m,cmp);
	for(int i=1;i<=m;i++){
		if(f[l[i].u]==0||f[l[i].v]==0) ans+=l[i].w,f[l[i].u]=1,f[l[i].v]=1;
	}
	cout<<ans<<"\n";
	return 0;
}