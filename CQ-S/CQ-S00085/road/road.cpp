#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,k;
ll c[11];
ll a[11][10001];
ll fa[10001];
ll cnt;
struct edge{
	ll u,v,w;
}r[1000001],e[1024][20001];
bool cmp(edge&a,edge&b) {
	return a.w<b.w;
}
ll find(ll x) {
	return fa[x]=(x==fa[x]?x:find(fa[x]));
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) {
		ll u,v,w;
		cin>>u>>v>>w;
		r[i]=(edge){u,v,w};
	}
	sort(r+1,r+1+m,cmp);
	for(int i=1;i<=n;i++) 
		fa[i]=i;
	ll tmp=0,cnt=0;
	for(int i=1;i<=m;i++) {
		if(find(r[i].u)!=find(r[i].v)) {
			fa[find(r[i].u)]=find(r[i].v);
			e[0][++cnt]=r[i];
			tmp+=r[i].w;
		}
	}
	ll ans=tmp;
	for(int i=0;i<k;i++) {
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	for(int i=1;i<(1<<k);i++) {
		ll se,res=0,tot=0,d=0;
		for(int j=0;j<k;j++)
			if((i>>j)&1)
				se=j,res+=c[j],d++;
		for(int j=1;j<n+d-1;j++)
			r[j]=e[i^(1<<se)][j];
		tot=n+d-2;
		for(int j=1;j<=n;j++)
			r[++tot]=(edge){n+se+1,j,a[se][j]};
		for(int j=1;j<=n+k;j++) 
			fa[j]=j;
		sort(r+1,r+1+tot,cmp);
		cnt=0;
		for(int j=1;j<=tot;j++) {
			if(find(r[j].u)!=find(r[j].v)) {
				fa[find(r[j].u)]=find(r[j].v);
				e[i][++cnt]=r[j];
				res+=r[j].w;
			}
		}
		ans=min(ans,res);
	}
	cout<<ans;
    return 0;
}

