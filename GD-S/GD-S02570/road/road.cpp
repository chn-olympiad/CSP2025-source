#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=1e4+5,M=2e6+5;
const ll INF=1e16;
int n,m,k;
struct node{int u,v;ll w;}edge[M],edge1[M];int tot;
int f[N];
int find(int x) {return f[x]==x?x:f[x]=find(f[x]);}
ll a[15][N];
void work1()
{
	for(int i=0;i<k;i++){
		for(int j=1;j<=n;j++) edge[++m]={n+i+1,j,a[i][j]};
	}
	sort(edge+1,edge+m+1,[](node p,node q){return p.w<q.w;});
	ll ans=0;
	for(int i=1;i<=n+k;i++) f[i]=i;
	int cnt=0;
	for(int i=1;i<=m;i++){
		int u,v;ll w;
		u=edge[i].u,v=edge[i].v,w=edge[i].w;
		u=find(u),v=find(v);
		if(u!=v){
			f[u]=v;
			ans+=w;
			cnt++;
			if(cnt==n+k-1) break;
		}
	}
	cout<<ans<<'\n';
}
void work2()
{
	sort(edge+1,edge+m+1,[](node p,node q){return p.w<q.w;});
	ll ans=INF;
	for(int i=0;i<(1<<k);i++){
		ll sum=0;int cnt=0;
		tot=0;
		for(int j=0;j<k;j++){
			if((i>>j)&1){
				sum+=a[j][0],cnt++;
				for(int jj=1;jj<=n;jj++) edge1[++tot]={n+j+1,jj,a[j][jj]};
			}
		}
		sort(edge1+1,edge1+tot+1,[](node p,node q){return p.w<q.w;});
		int now1=1,now2=1;
		for(int j=1;j<=n+k;j++) f[j]=j;
		int cnt1=0;
		for(int j=1;j<=m+tot;j++){
			int u,v;ll w;
			if(now1>m) u=edge1[now2].u,v=edge1[now2].v,w=edge1[now2].w,now2++;
			else if(now2>tot) u=edge[now1].u,v=edge[now1].v,w=edge[now1].w,now1++;
			else {
				if(edge1[now2].w<edge[now1].w) u=edge1[now2].u,v=edge1[now2].v,w=edge1[now2].w,now2++;
				else u=edge[now1].u,v=edge[now1].v,w=edge[now1].w,now1++;
			}
			u=find(u),v=find(v);
			if(u!=v){
				f[u]=v;
				sum+=w;
				cnt1++;
				if(cnt1==n+cnt-1) break;
			}
		}
		ans=min(ans,sum);
	}
	cout<<ans<<'\n';
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>edge[i].u>>edge[i].v>>edge[i].w;
	for(int i=0;i<k;i++) for(int j=0;j<=n;j++) cin>>a[i][j];
	bool flag=true;
	for(int i=0;i<k;i++) {
		if(a[i][0]!=0) {flag=false;break;}
		bool flag1=false;
		for(int j=1;j<=n;j++) if(a[i][j]==0) {flag1=true;break;}
		if(!flag1) {flag=false;break;}
	}
	if(flag) work1();
	else work2();
}
