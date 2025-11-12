/*
14:47 拼尽全力终于切出 T1

k=10，那么显然 k 是一个复杂度瓶颈，那么我们直接枚举城市化改造的乡镇集合

先求原图的最小生成树

想一下能否选最小生成树以外的边 
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+15,M=1e6+5;
int n,m,K,tot;
int fa[N],val[11][N];
ll ans;
struct Ed {
	int x,y,w;
}e1[M],e2[N*11];
int Find(int x) {
	return x==fa[x]?x:fa[x]=Find(fa[x]);
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>K;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) cin>>e1[i].x>>e1[i].y>>e1[i].w;
	sort(e1+1,e1+m+1,[](const Ed &x,const Ed &y) {
		return x.w<y.w;
	});
	for(int i=1,j=1;i<=m;i++) {
		int x=Find(e1[i].x),y=Find(e1[i].y);
		if(x==y) continue;
		ans+=e1[i].w;
		fa[x]=y;
		e1[j].x=e1[i].x;
		e1[j].y=e1[i].y;
		e1[j].w=e1[i].w;
		++j;
	}
	for(int i=1;i<=K;i++) {
		for(int j=0;j<=n;j++) cin>>val[i][j];
	}
	int all=(1<<K)-1;
	for(int S=0;S<=all;S++) {
		ll res=0;
		for(int i=1;i<=n+K;i++) fa[i]=i;
		for(int i=1;i<n;i++) e2[i]=e1[i];
		tot=n-1;
		for(int i=1;i<=K;i++)
			if((S>>i-1)&1) {
				res+=val[i][0];
				for(int j=1;j<=n;j++) {
					++tot;
					e2[tot].x=n+i;
					e2[tot].y=j;
					e2[tot].w=val[i][j];
				}
			}
		sort(e2+1,e2+tot+1,[](const Ed &x,const Ed &y) {
			return x.w<y.w;
		});
		for(int i=1;i<=tot;i++) {
			int x=Find(e2[i].x),y=Find(e2[i].y);
			if(x==y) continue;
			res+=e2[i].w;
			fa[x]=y;
		}
		ans=min(ans,res);
	}
	cout<<ans;
	return 0;
}
