#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,fa[10001],p[20][10001];
struct ox{ll u,v,x;};ox z[1000001];
ll cmp(ox a,ox b) {return a.x<b.x;}
ll find(ll x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]); 
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++)
		cin>>z[i].u>>z[i].v>>z[i].x;
	for(ll i=1;i<=k;i++){
		for(ll j=0;i<=n;i++) cin>>p[i][j];
	}
	
		std::sort(z+1,z+m+1,cmp);
		for(ll i=1;i<=n;i++) fa[i]=i;
		ll cnt=0,ans=0;
		for(ll i=1;i<=m;i++){
			ll a=find(z[i].u),b=find(z[i].v);
			if(a!=b){
				fa[a]=b;
				cnt++;ans+=z[i].x;
				if(cnt==n-1) break;
			}
			else continue;
		}
		cout<<ans<<"\n";
		
	return 0;
} 
/*
如果不考虑村庄，直接一个最小生成树 

然后我忘了 
*/
