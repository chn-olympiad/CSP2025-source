#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
ll head[2000020],cnt,f[20020],d[1010][1010];
struct edge{
	ll u,v,w;
}e[2000020];
struct city{
	ll c,d[10010];
}c[11];
bool cmp(edge z,edge h){
	return z.w<h.w;
}
ll find(ll x){
	if(f[x]==x){
		return x;
	}
	return f[x]=find(f[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll s,z,h,zh=0;
	cin>>s>>z>>h;
	if(h==0){
		for(ll i=0;i<=s;i++){
			f[i]=i;
		}
		for(ll i=0;i<z;i++){
			cin>>e[i].u>>e[i].v>>e[i].w;
		}
		sort(e,e+z,cmp);
		for(ll i=0;i<z;i++){
			ll u=find(e[i].u),v=find(e[i].v);
			if(u!=v){
				zh+=e[i].w;
				f[u]=v;
			}
		}
		cout<<zh;
		return 0;
	}
	for(ll i=0;i<=s;i++){
		f[i]=i;
		for(ll j=0;j<=s;j++){
			d[i][j]=2e9+10;
		}
	}
	for(ll i=0;i<z;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		d[u][v]=min(d[u][v],w);
	}
	for(ll i=1;i<=h;i++){
		cin>>c[i].c;
		for(ll j=1;j<=s;j++){
			cin>>c[i].d[j];
		}
		for(ll j=1;j<=s;j++){
			for(ll k=1;k<=s;k++){
				d[j][k]=min(d[j][k],c[i].d[j]+c[i].d[k]);
			}
		}
	}
	ll s2=0;
	for(ll i=1;i<=s;i++){
		for(ll j=1;j<=s;j++){
			if(d[i][j]!=2e9+10){
				e[s2].u=i,e[s2].v=j,e[s2].w=d[i][j];
				s2++;
			}
		}
	}
	sort(e,e+s2,cmp);
	for(ll i=1;i<s2;i++){
		ll u=find(e[i].u),v=find(e[i].v);
		if(u!=v){
			zh+=e[i].w;
			cout<<e[i].w<<"\n";
			f[u]=v;
		}
	}
	cout<<zh;
	return 0;
}
