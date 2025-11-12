#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1e18;
int n,m,k,cnt,c[15],b[15][1000005],ans,now,maxn,minn;
struct node{
	int x,y,w;
}h[2000005],a[2000005],d[2000005];
bool cmp(node a,node b){
	return a.w<b.w;
}
int fa[2000005];
void init(){
	for(int i=1;i<=n+k;i++) fa[i]=i;
}
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
bool merge(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y) return false;
	fa[x]=y;
	return true;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>h[i].x>>h[i].y>>h[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>b[i][j];
		}
	}
	sort(h+1,h+1+m,cmp);
	init();
	for(int i=1;i<=m;i++){
		if(merge(h[i].x,h[i].y)) d[++cnt]=h[i],maxn=max(maxn,h[i].w);
	}
	minn=inf;
	for(int s=0;s<(1<<k);s++){
		init();
		cnt=n-1,now=0,ans=0;
		for(int i=1;i<n;i++) a[i]=d[i];
		for(int i=1;i<=k;i++){
			if(s&(1<<(i-1))){
				ans+=c[i];
				for(int j=1;j<=n;j++){
					if(b[i][j]<maxn) a[++cnt]={i+n,j,b[i][j]};
				}
			}
		}
		sort(a+1,a+1+cnt,cmp);
		for(int i=1;i<=cnt;i++){
			if(merge(a[i].x,a[i].y)) ans+=a[i].w,now++;
			if(now==n+__builtin_popcount(s)-1) break;
		}
		minn=min(minn,ans);
	}
	cout<<minn;
	return 0;
}
