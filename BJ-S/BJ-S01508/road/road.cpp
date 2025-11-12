#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10,M=1e5+10;
struct node{
	ll x,y,z;
}e[N*2];
ll a[N];
ll fa[N];
bool v[1010][1010];
bool cmp(node n1,node n2){
	return n1.z<n2.z;
}
ll find(ll x){
	if(x==fa[x]) return fa[x];
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ll n,m,k;
	cin>>n>>m>>k;
	ll ma=-1;
	memset(v,0x3f,sizeof(v));
	for(int i=1;i<=m;i++){
		cin>>e[i].x>>e[i].y>>e[i].z;
		v[e[i].x][e[i].y]=v[e[i].x][e[i].y]=e[i].z;
		ma=max(ma,e[i].z);
	}
	ll tot=m;
	while(k--){
		memset(a,0,sizeof(a));
		ll x;
		cin>>x;
		if(x>=ma) continue;
		for(ll i=1;i<=n;i++){
			cin>>a[i];
		}
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				if(a[i]+a[j]+x>=v[i][j]) continue;
				e[++tot].x=i;
				e[tot].y=j;
				e[tot].z=a[i]+a[j]+x;
			}
		}
	}
	for(ll i=1;i<=n;i++) fa[i]=i;
	sort(e+1,e+tot+1,cmp);
	ll ans=0;
	for(ll i=1;i<=tot;i++){
		ll fx=find(e[i].x);
		ll fy=find(e[i].y);
		if(fx!=fy){
			fa[fx]=fy;
			ans+=e[i].z;
		}
	}
	cout<<ans;
	return 0;
}
