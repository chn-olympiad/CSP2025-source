#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,c[15],w[15][100005],fa[100015],l,ans=1e16,cnt,vis[15];
struct o{
	int x,y,z;
}a[1000005],b[1100005],hh[10005];
bool cmp(o x,o y){
	return x.z<y.z;
}
int get(int x){
	return fa[x]==x?x:fa[x]=get(fa[x]);
}
void f(){
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(int i=1;i<=l;i++){
		if(b[i].x>n&&!vis[b[i].x-n])continue;
		int xx=get(b[i].x),yy=get(b[i].y);
		if(xx!=yy){
			cnt+=b[i].z;
			fa[xx]=yy;
		}
	}
}
signed main(){
	cin.tie(0),cout.tie(0),ios::sync_with_stdio(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
	}
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		int xx=get(a[i].x),yy=get(a[i].y);
		if(xx!=yy){
			b[++l]={a[i].x,a[i].y,a[i].z};
			fa[xx]=yy;
		}
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>w[i][j];
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++)
			b[++l]={n+i,j,w[i][j]};
	}
	sort(b+1,b+1+l,cmp);
	for(int i=0;i<(1<<k);i++){
		cnt=0;
		memset(vis,0,sizeof vis);
		for(int j=1;j<=k;j++)
			if((i>>(j-1))&1)cnt+=c[j],vis[j]=1;
		f();
		ans=min(ans,cnt);
	}
	cout<<ans;
	return 0;
}
