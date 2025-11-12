#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,ans=1e18;
ll c[15];
ll b[15][10005];
ll fa[20005];
struct node{
	ll x,y,z;
	node(ll xx,ll yy,ll zz){
		x=xx;
		y=yy;
		z=zz;
	}
};
bool operator < (node x,node y){return x.z>y.z;}
priority_queue<node>p;
ll gf(ll x){return fa[x]==x?x:fa[x]=gf(fa[x]);}
void dfs(ll kk,ll s,ll cnt){
	if(s>=ans) return;
	if(kk>k){
		for(int i=1;i<=n+k;i++) fa[i]=i;
		ll tot=0;
		while(tot<n+(cnt-m)/n-1&&!p.empty()){
			node t=p.top();
			p.pop();
			ll fx=gf(t.x);
			ll fy=gf(t.y);
			if(fx!=fy){
				fa[fx]=fy;
				s+=t.z;
				tot++;
			}
		}
		ans=min(ans,s);
		return;
	}
	auto q=p;
	for(int i=1;i<=n;i++) p.push(node(n+kk,i,b[kk][i]));
	dfs(kk+1,s+c[kk],cnt+n);
	p=q;
	dfs(kk+1,s,cnt);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL),cout.tie(NULL);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		ll x,y,z;
		cin>>x>>y>>z;
		p.push(node(x,y,z));
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>b[i][j];
	}
	dfs(1,0,m);
	cout<<ans<<"\n";
	return 0;
}
