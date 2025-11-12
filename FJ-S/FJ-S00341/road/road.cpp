//CSP-S AK me
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=10005,M=1000005;
int n,m,k,c[15],a[15][N],fa[N],ans=0;
struct qwq{
	int u,v,w;
} ee[M];
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
bool cmp(qwq a,qwq b){
	return a.w<b.w;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		ee[i]={u,v,w};
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	sort(ee+1,ee+m+1,cmp);
	for(int i=1;i<=m;i++){
		int p=find(ee[i].u),q=find(ee[i].v);
		if(p!=q){
			fa[p]=q;
			ans+=ee[i].w;
		}
	}
	cout<<ans;
	return 0;
}
