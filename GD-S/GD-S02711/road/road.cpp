#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e4+10;
ll n,m,k,c,x,cnt,ans,u,v,w,f[N],num;
bool d=0;
struct node{
	ll u,v,w;
};
vector<node>a;
bool cmp(node x,node y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		cin>>u>>v>>w;
		a.push_back({u,v,w});
	}
	for(ll i=1;i<=k;i++){
		cin>>c;
		bool b=1;
		for(ll j=1;j<=n;j++){
			cin>>x;
			if(x) b=0;
		}
		if(b) d=1;
	}
	if(d){
		cout<<0;
		return 0;
	}
	sort(a.begin(),a.end(),cmp);
	for(ll i=0;i<a.size()&&cnt<m-1-num;i++){
		if(!f[a[i].u]||!f[a[i].v]||f[a[i].u]!=f[a[i].v]){
			ans+=a[i].w;
			f[a[i].u]=f[a[i].v]=a[i].u;
			cnt++;
		}
	}
	cout<<ans;
	return 0;
}
