#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ans=1e18,n,m,k,c[20],b[20][10010],f[10010];
vector<ll>bj;
struct tt{
	ll x,y,d;
};
vector<tt>a,aa;
ll find(ll x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
bool cmp(tt a,tt b){
	return a.d<b.d;
}
ll work(vector<tt>a,ll n){
	for(ll i=1;i<=n;i++) f[i]=i;
	sort(a.begin(),a.end(),cmp);
	ll ans=0;
	for(ll i=0;i<a.size();i++){
		ll u=a[i].x,v=a[i].y,w=a[i].d;
		ll du=find(u),dv=find(v);
		if(du!=dv){
			f[dv]=du;
			ans+=w;
		}
	}
	return ans;
}
void dfs(int l){
	if(l==k+1){
		aa.clear();
		for(auto k:a) aa.push_back(k);
		ll la=n,sum=0;
		for(auto l:bj){
			la++,sum+=c[l];
			for(ll i=1;i<=n;i++){
				aa.push_back({i,la,b[l][i]});
			}
		}
		ans=min(ans,work(aa,la)+sum);
	}else{
		bj.push_back(l);
		dfs(l+1);
		bj.erase(bj.end()-1);
		dfs(l+1);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(nullptr),cout.tie(nullptr),ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(ll i=1,x,y,d;i<=m;i++){
		cin>>x>>y>>d;
		a.push_back({x,y,d});
	}
	for(ll i=1;i<=k;i++){
		cin>>c[i];
		for(ll j=1;j<=n;j++){
			cin>>b[i][j];
		}
	}
	dfs(1);
	cout<<ans;
	return 0;
}
