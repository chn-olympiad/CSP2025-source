#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+5,M=1e6+5;
int n,m,k,len,ans=1e18,c[15],a[15][N],fa[N<<1];
struct node{int x,y,z;}e[M],d[M];
bool cmp(node X,node Y){return X.z<Y.z;}
int fd(int x){
	if(x==fa[x])return x;
	return fa[x]=fd(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>e[i].x>>e[i].y>>e[i].z;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j]; 
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		int x=fd(e[i].x),y=fd(e[i].y);
		if(x==y)continue;
		fa[x]=y,d[++len]=e[i]; 
	}
	m=len;
	for(int i=1;i<=m;i++)e[i]=d[i];
	for(int w=0;w<(1<<k);w++){
		int res=0,cnt=0;
		for(int i=1;i<=k;i++){
			if(!((w>>(i-1))&1))continue;
			res+=c[i],cnt++;
			for(int j=1;j<=n;j++)e[++m]={n+cnt,j,a[i][j]};
		}
		sort(e+1,e+m+1,cmp);
		for(int i=1;i<=n+cnt;i++)fa[i]=i;
		for(int i=1;i<=m;i++){
			int x=fd(e[i].x),y=fd(e[i].y);
			if(x==y)continue;
			fa[x]=y,res+=e[i].z;
			if(res>=ans)break;
		}
		ans=min(ans,res),m=len;
		for(int i=1;i<=m;i++)e[i]=d[i];
	}
	cout<<ans;
	return 0;
}
