#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define dbg(x) cout<<#x<<'='<<x<<endl;
#define ll long long
int n,m,k;
int fa[100010];
ll a[20][100010];
ll c[20];
int b[20];
ll ans=0;
vector<pair<ll,pair<ll,ll>>>q1,q2,q3;
int myfind(int x){
	if(fa[x]==x)return x;
	return fa[x]=myfind(fa[x]);
}
void Union(int x,int y){
	fa[myfind(x)]=myfind(y);
	return ; 
}
void dfs(int step){
	if(step==k+1){
		ll now=0;
		q3=q2;
		for(int i=1;i<=k;i++)if(b[i]){
			now+=c[i];
			for(int j=1;j<=n;j++)q2.push_back({a[i][j],{n+i,j}});
		}
		sort(q2.begin(),q2.end());
		for(int j=1;j<=n+k;j++)fa[j]=j;
		for(auto j:q2){
			ll w=j.first;
			ll u=j.second.first;
			ll v=j.second.second;
			if(myfind(u)!=myfind(v)){
				Union(u,v);
				now+=w;
			}
		}
		if(now<ans)ans=now;
		q2=q3;
		return ;
	}
	for(int i=0;i<=1;i++){
		b[step]=i;
		dfs(step+1);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		q1.push_back({w,{u,v}});
	}
	sort(q1.begin(),q1.end());
	for(int i=1;i<=n;i++)fa[i]=i;
	for(auto i:q1){
		ll w=i.first;
		ll u=i.second.first;
		ll v=i.second.second;
		if(myfind(u)!=myfind(v)){
			Union(u,v);
			ans+=w;
			q2.push_back({w,{u,v}});
		}
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
} 
