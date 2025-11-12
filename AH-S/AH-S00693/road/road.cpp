#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const ll N=1e4+20,M=1e6+10;
ll n,tn,m,k,u,v,w;
ll T[N],town[20];

struct vex{int u,v,w;} G[N];

bool cmp(const vex &x,const vex &y){
	return x.w<y.w;
}
int find(int x){
	if(T[x]!=x) T[x]=find(T[x]);
	return T[x];
}

ll f1(){
	ll ans=0,cnt=0;
	sort(G+1,G+n+1,cmp);
	for(ll i=1;i<=n;i++) T[i]=i;
	for(ll i=1;i<=m;i++){
		ll u=G[i].u,v=G[i].v,w=G[i].w;
		ll Ra=find(u),Rb=find(v);
		if(Ra!=Rb){
			T[Ra]=Rb;
			ans+=w;
		}
		if(cnt==n-1) break;
	}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m>>k; tn=n;
	for(ll i=1;i<=m;i++){
		cin>>G[i].u>>G[i].v>>G[i].w;
	}
	for(ll i=1;i<=k;i++){
		cin>>town[i];
		for(ll j=1;j<=n;j++){
			cin>>G[i*n+m+j].w;
			G[i*n+m+j].v=j;
			G[i*n+m+j].u=++tn;
		}
	}
	cout<<f1();
	return 0;
}
