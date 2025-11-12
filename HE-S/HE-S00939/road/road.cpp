#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct h {
	ll a,b,c;
} v[2000000];
ll n,m,k,fa[10100],kn,ans;
bool cmp(h x,h y) {
	return x.c<y.c;
}
ll find(ll x) {
	if(fa[x]==x) {
		return x;
	}
	find(fa[x]);
}
void marge(int x) {
	int a=find(v[x].a),b=find(v[x].b);
	if(a!=b) {
		fa[a]=b;
		ans+=v[x].c;
	}
}

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	kn=k*n+m;
	for(ll i=0; i<10088; i++) fa[i]=i;
	for(ll i=1; i<=m; i++) {
		ll a,b,c;
		cin>>a>>b>>c;
		v[i].a=a,v[i].b=b,v[i].c=c;

	}
	int f=m;
	for(ll i=1; i<=k; i++) {
		ll c;
		cin>>c;
		for(ll j=1; j<=n; j++) {
			ll a;
			cin>>a;
			v[++f].a=n+i+1,v[f].b=j,v[f].c=a;
		}
	}

	sort (v+1,v+kn+1,cmp);
	for(ll i=1; i<=kn; i++) {
		marge(i);
	}
	cout <<ans;
	fclose(stdin);
	fclose(stdout);

	return 0;
}
