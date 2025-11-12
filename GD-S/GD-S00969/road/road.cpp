#include <bits/stdc++.h>
#define ll long long
#define maxn 1000010
using namespace std;

struct edge {
	ll u,v,w;
} E[maxn*2];
ll c[20],mx[20];//城市化第i个乡镇的最大收益 
ll f[10010],ans;

ll fr(ll x) {
	if (f[x]==x) return x;
	return f[x]=fr(f[x]);
}

bool cmp(edge x,edge y) {
	return x.w<y.w;
}

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	ll n,m,k;
	cin>>n>>m>>k;
	for (int i=1;i<=n+k;i++) f[i]=i;
	for (int i=1;i<=m;i++) {
		ll u,v,w;
		cin>>u>>v>>w;
		E[i].u=u; E[i].v=v; E[i].w=w;
	}
	for (int i=1;i<=k;i++) {
		cin>>c[i];
		for (int j=1;j<=n;j++) {
			ll w;
			cin>>w;
			E[++m].u=i+n; E[m].v=j; E[m].w=w;
		}
	}
	sort(E+1,E+1+m,cmp);
	for (int i=1;i<=m;i++) {
		ll u=E[i].u, v=E[i].v, w=E[i].w;
		ll ru=fr(u), rv=fr(v);
		if (ru!=rv) {
			f[ru]=rv;
			ans+=w;
		}
	}
	cout<<ans;
	return 0;
}
