#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k;
ll f[10010];
ll c[10010][10010]; //city
ll o[10010][10010];
ll s=0;
list<ll> l;

struct aaa{
	bool f;
	int c;
	ll a[10010];
}ur[11];
struct aa{
	int u,v,w;
}road[1000001];

ll fa(ll x){
	if(f[x]==x) return x;
	else return fa(f[x]);
}
void bing(ll x,ll y){
	
}

void solve(){
	for(ll i=1;i<=n;i++) f[i]=i;
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		cin>>road[i].u;
		cin>>road[i].v;
		cin>>road[i].w;
		c[road[i].v][road[i].u]=c[road[i].u][road[i].v]=road[i].w;
		if(road[i].v>road[i].u) swap(road[i].v,road[i].u);
	}
	for(ll i=1;i<=k;i++){
		ur[i].f=0;
		cin>>ur[i].c;
		for(ll j=1;j<=n;j++){
			cin>>ur[i].a[j];
		}
		for(ll j=1;j<=n;j++){
			for(ll x=j+1;x<=n;x++){
				if(o[j][x]==0||ur[i].a[j]+ur[i].a[x]+ur[i].c<=ur[o[j][x]].a[j]+ur[o[j][x]].a[x]+ur[o[j][x]].c){
					o[j][x]=o[x][j]=i;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(road[i].w>=(ur[o[road[i].u][road[i].v]].c)*(1-ur[o[road[i].u][road[i].v]].f)+ur[o[road[i].u][road[i].v]].a[road[i].v]+ur[o[road[i].u][road[i].v]].a[road[i].u]){
			ur[o[road[i].u][road[i].v]].f=1;
		}
	}
	for(int i=1;i<=m;i++){
		if(road[i].w>=(ur[o[road[i].u][road[i].v]].c)*(1-ur[o[road[i].u][road[i].v]].f)+ur[o[road[i].u][road[i].v]].a[road[i].v]+ur[o[road[i].u][road[i].v]].a[road[i].u]){
			ur[o[road[i].u][road[i].v]].f=1;
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=i+1;j<=n;j++){
//			if(c[i][j]>=ur[o[i][j]].a[i]+ur[o[i][j]].a[j]+ur[o[i][j]].c*(1-ur[o[i][j]].f)){
//				if(ur[o[i][j]].f){	
//					s+=ur[o[i][j]].a[i]+ur[o[i][j]].a[j];
//				}else{
//					s+=ur[o[i][j]].a[i]+ur[o[i][j]].a[j]+ur[o[i][j]].c;
//					ur[o[i][j]].f=1;
//
//				}
//			}
//		}
//	}
	cout<<s;
	return;
}

int main(){
	freopen("road1.in","r",stdin);
//	freopen("road.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ll T=1;
	while(T--){
		solve();
	}
	return 0;
}
