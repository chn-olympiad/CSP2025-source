#include<bits/stdc++.h>
#define int long long
using namespace std;
struct edge{
	int x,y,w;
}e[2000005];
int n,m,k,cnt,co[20],fa[200005],ans,mi=1e18;
bool fl=1,xu[20];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cnt++;
		cin>>e[cnt].x>>e[cnt].y>>e[cnt].w;
	}
	for(int i=1;i<=k;i++){
		cin>>co[i];
		if(co[i])	fl=0;
		bool nfl=0;
		for(int j=1;j<=n;j++){
			int x;cin>>x;
			e[++cnt]=edge{n+i,j,x};
			if(!x)	nfl=1;
		}
		fl&=nfl;
	}
	sort(e+1,e+cnt+1,cmp);
	if(fl){
		for(int i=1;i<=n+k;i++)	fa[i]=i;
		ans=0;
		for(int i=1;i<=cnt;i++){
			int rx=find(e[i].x),ry=find(e[i].y);
			if(rx!=ry){
				fa[rx]=ry;
				ans+=e[i].w;
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=0;i<(1<<k);i++){
		int u=i;
		memset(xu,0,sizeof xu);
		ans=0;
		for(int j=1;j<=k;j++)
			if(u&(1<<j-1)){
				xu[j]=1;
				ans+=co[j];
			}
		if(ans>=mi)	continue;
		for(int i=1;i<=n+k;i++)	fa[i]=i;
		for(int i=1;i<=cnt;i++){
			if(e[i].x>n&&!xu[e[i].x-n])	continue;
			if(e[i].y>n&&!xu[e[i].y-n])	continue;
			int rx=find(e[i].x),ry=find(e[i].y);
			if(rx!=ry){
				fa[rx]=ry;
				ans+=e[i].w;
				if(ans>=mi)	break;
			}
		}
		mi=min(mi,ans);
	}
	cout<<mi;
	return 0;
}
