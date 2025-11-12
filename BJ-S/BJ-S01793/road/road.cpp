#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1e6+5;
const int N=1e4+5;
ll n,m,k;
class node{
public:
	ll u,v,w;
} edge[M];
ll f[N];
ll change[15][N],c[15];
ll fd(ll x){
	if(x==f[x]) return x;
	return f[x]=fd(f[x]);
}
bool cmp(node n1,node n2){
	return n1.w<n2.w;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		cin>>edge[i].u>>edge[i].v>>edge[i].w;
	}
	for(ll i=1;i<=n;i++) f[i]=i;
	for(ll i=1;i<=k;i++){
		cin>>c[i];
		for(ll j=1;j<=n;j++) cin>>change[i][j];
	}
	sort(edge+1,edge+1+m,cmp);
	ll ans=0,cnt=0;
	for(ll i=1;i<=m;i++){
		if(cnt==n-1) break;
		else if(fd(edge[i].u)!=fd(edge[i].v)){
			ans+=edge[i].w,cnt++;
			f[edge[i].v]=f[edge[i].u];
		} 
	}
	cout<<ans;
	return 0;
}
