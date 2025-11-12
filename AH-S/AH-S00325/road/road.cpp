#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dis[1100000];
struct OP{
	ll u,w;
	bool p;
}cpt;
vector<OP> g[1100000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ll m,n,k,maxn=0,lmaxn=0;
	cin>>m>>n>>k;
	for(ll i=1;i<=n;i++){
		ll u,v,w;
		scanf("%lld %lld %lld",&u,&v,&w);
		cpt.u=v,cpt.w=w,cpt.p=0;
		g[u].push_back(cpt);
		cpt.u=u,cpt.w=w,cpt.p=0;
		g[v].push_back(cpt);
	}
	for(ll j=1;j<=m;j++){
		ll len=g[j].size(),minn=1e9,op=0,oe=0,oep=0;
		for(ll k=0;k<len;k++){
			if(g[j][k].p==0&&minn>g[j][k].w){
				oe=k;
				op=g[j][k].u;
				minn=g[j][k].w;
			}
		}
		len=g[oe].size();
		for(ll k=0;k<len;k++){
			if(g[oe][k].u==j){
				oep=k;
			}
		}
		if(op!=0){
			g[j][oe].p=1;
			g[op][oep].p=1;
			cout<<j<<" "<<oe<<endl;
			cout<<op<<" "<<oep<<endl;
		}
		if(minn!=1e9) maxn+=minn;
		lmaxn=max(lmaxn,minn);
	}
	cout<<maxn-lmaxn;
	return 0;
}
