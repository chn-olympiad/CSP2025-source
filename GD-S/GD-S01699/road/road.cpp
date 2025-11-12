#include<bits/stdc++.h>
#define ll long long
#define N 10005
using namespace std;
int n,m,k,c[N],used[11],fa[N];
ll a[11][N];
vector<int> v[N];
vector<ll> w[N];
int getfa(int x){
	if(fa[x]==x)return x;
	return fa[x]=getfa(fa[x]);
}
struct A{
	int x,y,id;
	ll val;
	bool operator <(const A a) const{
		return val>a.val;
	}
};
priority_queue<A> q;
int build(){
	for(int i=1;i<=n;i++){
		fa[i]=i;
		int l=v[i].size();
		for(int j=0;j<l;j++){
			q.push({i,v[i][j],j,w[i][j]});
		}
	}
	int cnt=0;ll ans=0;
	while(!q.empty()){
		A f=q.top();q.pop();
		int x=f.x,y=f.y,id=f.id;
		ll val=f.val;
		if(getfa(x)==getfa(y))continue;
		ans+=val;
		fa[getfa(x)]=fa[y];
		if(cnt==n-1)break;
	}
	return ans;
}
void solve(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		v[x].push_back(y),v[y].push_back(x);
		w[x].push_back(z),w[y].push_back(z);
	}
	ll ans=build();
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",a[i][j]);
		}
	}
	printf("%lld",ans);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	solve();
	return 0;
}
