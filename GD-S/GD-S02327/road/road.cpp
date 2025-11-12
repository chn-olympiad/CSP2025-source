#include<bits/stdc++.h>
using namespace std;
#define is(x) isdigit(x)
#define g getchar()
typedef unsigned int ll;
typedef pair<ll,pair<ll,ll>> ppll;
inline void r(ll &x){
	x=0;char c=g;ll f=1;
	while(!is(c)){
		if(c=='-'){
			f*=-1;
		}
		c=g;
	}
	while(is(c)){
		x=(x<<1)+(x<<3)+(c^48);
		c=g;
	}
	x*=f;
	return ;
}
const ll N=2e4;
ll ans=0,cnt,n,m,k,x,y,v,f[N],fk[20][N],use[20],vl[20];
map<int,short>mp;
ll find(ll x){
	return f[x]==x?x:f[x]=find(f[x]);
}
vector<pair<ll,ll>>vt[10*N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	r(n);r(m);r(k);
	priority_queue<ppll,vector<ppll>,greater<ppll>>q;
	for(int i=1;i<=m;i++){
		r(x);r(y);r(v);
		vt[x].push_back({v,y});
		vt[y].push_back({v,x});
	}
	for(int i=1;i<=n+k;i++){
		f[i]=i;
	}
	for(int i=1;i<=k;i++){
		r(vl[i]);
		for(int j=1;j<=n;j++){
			r(fk[i][j]);
			vt[j].push_back({fk[i][j],i+n});
			vt[i+n].push_back({fk[i][j],j});
		}
	}
	for(auto i:vt[1]){
		q.push({i.first,{1,i.second}});
	}
	mp[1]++;
	while(cnt!=n-1){
		auto i=q.top();
		q.pop();
		ll c=i.second.first,d=i.second.second,a=find(i.second.first),b=find(i.second.second);
		if(a!=b){
			if(c>n){
				if(!mp[c]){
					for(int i=0;i<vt[c].size();i++){
						vt[c][i].first+=vl[c-n];
					}
					use[c-n]=i.first;
				}
				else{
					cnt++;
				}
			}else if(d>n){
				if(!mp[d]){
					for(int i=0;i<vt[d].size();i++){
						vt[d][i].first+=vl[d-n];
					}
					use[d-n]=i.first;
				}
				else{
					cnt++;
				}
			}
			else{
				cnt++;
			}
			ans+=i.first;
			f[a]=f[b];
			if(!mp[a]){
				for(auto j:vt[a]){
					q.push({j.first,{a,j.second}});
				}
			}
			else if(!mp[b]){
				for(auto j:vt[b]){
					q.push({j.first,{b,j.second}});
				}
			}
			mp[i.second.first]++;mp[i.second.second]++;
		}
	}
	for(int i=1;i<=k;i++){
		if(mp[i+n]==1){
			ans-=use[i];
		}
	}
	printf("%lld",ans);
	return 0;
}
