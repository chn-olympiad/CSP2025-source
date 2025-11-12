#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e4+5;
ll n,m,k,ans=LLONG_MAX;
struct road{
	ll u,v,w;
	bool operator > (const road &dt) const{
		return w>dt.w;
 	}
};
priority_queue<road,vector<road>,greater<road> >a,b;
ll pa[N+10];
ll findpa(ll now){
	if(pa[now]!=0) return pa[now]=findpa(pa[now]);
	return now;
}
ll Kru(ll now){
	memset(pa,0,sizeof pa);
	a=b; ll cos=0;
	ll poi=now+n;
	while(poi>1){
		road line=a.top();
		a.pop();
		if(findpa(line.u)!=findpa(line.v)){
			cos+=line.w;
			pa[findpa(line.u)]=findpa(line.v);
			poi--;
		}
	}return cos;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		b.push({u,v,w});
	}ans=min(ans,Kru(0));
	for(int i=1;i<=k;i++){
		ll val;
		cin>>val;
		for(int j=1;j<=n;j++){
			ll w;
			cin>>w;
			b.push({i+n,j,w});
		}ans=min(ans,Kru(i)+val);
	}cout<<ans;
	return 0;
}
