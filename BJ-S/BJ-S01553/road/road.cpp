#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
const int M = 4e6+5;
int n,m,k,fa[N],c[N],tot,a[15][N];
struct Node{
	int u,v,val,tag;
}e[M];
inline bool cmp(Node x,Node y){
	return x.val<y.val;
}
inline int find(int x){
	return fa[x]==x?x:(fa[x]=find(fa[x]));
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1,u,v,val;i<=m;i++){
		cin>>u>>v>>val;
		e[++tot].u=u,e[tot].v=v,e[tot].val=val,e[tot].tag=-1;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	long long ans=9e18;
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++)
			e[++tot].u=n+i,e[tot].v=j,e[tot].val=a[i][j],e[tot].tag=i-1;
	stable_sort(e+1,e+1+tot,cmp);
	for(int mask=0;mask<(1<<k);mask++){
		long long res=0;
		int tot2=tot; int num=0;
		for(int i=0;i<k;i++)
			if(mask&(1<<i)) num++,res+=c[i+1];
		int cnt=0,t=1;
		for(int i=1;i<=n+num+2;i++) fa[i]=i;
		while(cnt!=n+num-1 && t<=tot){
			int x=e[t].u,y=e[t].v,val=e[t].val,tag=e[t].tag;
			if(tag==-1 || mask&(1<<tag)){
				int fx=find(x),fy=find(y);
				if(fx!=fy){
					res+=val*1ll;
					fa[fy]=fx;
					cnt++;
				}
			}
			t++;
		}
		if(cnt==n+num-1) ans=min(ans,res);
	}
	cout<<ans<<'\n';
	return 0;
}