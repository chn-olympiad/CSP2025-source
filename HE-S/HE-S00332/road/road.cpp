#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,K,cnt,fa[10100],a[20][10010],val[20];
ll ans;
struct edge{
	int x,y,w,f;
}e[1000010],e2[200010];
inline bool cmp(edge x,edge y){return x.w<y.w;}
inline int find(int x){
	return fa[x]=(fa[x]==x?x:find(fa[x]));
}
int popcount(int x){
	int ans=0;
	while(x){
		ans++;
		x^=x&(-x);
	}
	return ans;
}
signed main(){
//	system("fc road.out road2.ans"); return 0;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int x;
	cin>>n>>m>>K;
	for(int i=1;i<=m;i++) cin>>e[i].x>>e[i].y>>e[i].w;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int x=e[i].x,y=e[i].y;
		if(find(x)==find(y)) continue;
		e2[++cnt]=e[i];
		fa[find(y)]=find(x);
		ans+=e[i].w;
	}
	for(int i=1;i<=cnt;i++) e[i]=e2[i];
	m=cnt;
	for(int i=1;i<=K;i++){
		cin>>val[i];
		for(int j=1;j<=n;j++){
			cin>>x;
			e[++m].x=n+i;
			e[m].y=j;
			e[m].w=x;
			e[m].f=i;
		}
	}
	sort(e+1,e+m+1,cmp);
	for(int S=1;S<(1<<K);S++){
		int sum=n+popcount(S)-1;
		ll anss=0;
		for(int i=1;i<=K;i++) if(S&(1<<(i-1))) anss+=val[i];
		for(int i=1;i<=n+K;i++) fa[i]=i;
		for(int i=1;i<=m;i++){
			if(anss+1ll*sum*e[i].w>=ans) break;
			if(e[i].f && (!(S&(1<<(e[i].f-1))))) continue;
			int x=find(e[i].x),y=find(e[i].y);
			if(x==y) continue;
			fa[y]=x; anss+=e[i].w;
			if(!(--sum)) break;
		}
		if(!sum && anss<ans) ans=anss;
	}
	cout<<ans;
	return 0;
}
