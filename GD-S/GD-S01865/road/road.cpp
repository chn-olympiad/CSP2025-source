#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+5;
ll n,m,k;
struct node{
	ll u,v,w;
	bool friend operator<(node a1,node a2){
		return a1.w>a2.w;
	}
};
priority_queue<node> q;
ll f[N];
ll sz[N];
ll find(ll x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
bool cmp(node a1,node a2){
	return a1.w<a2.w;
}
vector<node> v2[15];
ll c[15];
priority_queue<node> q2;
ll kru(ll cnt){
	for(int i=1;i<=n+cnt;i++){
		f[i]=i;
		sz[i]=1;
	}
	ll ans=0,temp=0;
	while(!q2.empty()){
		ll x=q2.top().u,y=q2.top().v;
		ll w=q2.top().w;
		q2.pop();
		ll fx=find(x),fy=find(y);
		if(fx==fy) continue ;
		if(sz[fx]>sz[fy]) swap(fx,fy);
		f[fx]=fy;
		temp++;
		ans+=w;
		if(temp>=n+cnt-1){
			return ans;
		}
	}
	return INT_MAX;
}
void solve(){
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		ll x,y,z;
		cin >> x >> y >> z;
		q.push({x,y,z});
	}
	for(int i=1;i<=k;i++){
		cin >> c[i];
		for(int j=1;j<=n;j++){
			ll w;
			cin >> w;
			v2[i].push_back({i,j,w});
		}
	}
	for(int i=1;i<=n;i++){
		f[i]=i;
		sz[i]=1;
	}
	ll ans=0,temp=0;
	while(!q.empty()){
		ll x=q.top().u,y=q.top().v;
		ll w=q.top().w;
		q.pop();
		ll fx=find(x),fy=find(y);
		if(fx==fy) continue ;
		if(sz[fx]>sz[fy]) swap(fx,fy);
		f[fx]=fy;
		temp++;
		ans+=w;
		q2.push({x,y,w});
//		cout << x << " " << y << " " << w << "\n";
		if(temp>=n-1) break ;
	}
//	cout << "1---------------\n";
	priority_queue<node> pre;
	for(ll i=1;i<(1ll<<k);i++){
		ll cnt=0;
		ll num=0;
		pre=q2;
//		cout << "2---------------\n";
		for(ll j=1;j<=k;j++){
			if((i>>(j-1)&1)==1){
				num+=c[j];
				cnt++;
				for(auto x:v2[j]){
					q2.push({n+cnt,x.v,x.w});
				}	
			} 
		}
//		cout << "3---------------\n";
		ll tot=kru(cnt);
		ans=min(ans,tot+num);
//		cout << i << " " << tot << " " << num << " " << cnt << "\n";
		q2=pre;
	}
	cout << ans << "\n";
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}

