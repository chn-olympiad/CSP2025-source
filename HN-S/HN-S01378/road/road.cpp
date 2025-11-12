#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+10;
struct edge{
	int u,v,w;
}s[N];
int n,m,k,ans=0;
int c[N],fa[N];
int a[20][N];
int find(int x){
	if(fa[x]==x) return x;
	return find(fa[x]);
}
bool cmp(edge x,edge y){
	return x.w<y.w;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>s[i].u>>s[i].v>>s[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(s+1,s+1+m,cmp);
	for(int i=1;i<=n;i++){
		int x=s[i].u,y=s[i].v,w=s[i].w;
		x=find(x),y=find(y);
		if(x==y) continue;
		fa[y]=x;
		ans+=w;
	}
	cout<<ans<<"\n";
	return 0;
}
