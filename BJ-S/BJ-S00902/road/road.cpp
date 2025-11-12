#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fre(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
struct edge{int x,y,z;};
bool cmp(const edge&a,const edge&b){return a.z<b.z;}
#define bs basic_string<edge>
int f[10030],n,m,k;
bs es,es1[20];
ll c[1024];
int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
pair<bs,ll>slv(const bs&t){
	bs res;ll ans=0;iota(f,f+n+k+1,0);
	for(auto[x,y,z]:t){
		x=find(x),y=find(y);
		if(x!=y)ans+=z,f[x]=y,res+={x,y,z};
	}
	return{res,ans};
}
pair<bs,ll>dp[1024];
bitset<1024>vis;
int main(){
	cin.tie(0)->sync_with_stdio(0),fre("road");
	cin>>n>>m>>k,es.resize(m);
	for(int i=0;i<m;++i)cin>>es[i].x>>es[i].y>>es[i].z;
	sort(es.begin(),es.end(),cmp);
	for(int i=1;i<=k;++i){
		cin>>c[1<<(i-1)],es1[i].reserve(n);
		for(int j=1,a;j<=n;++j)cin>>a,es1[i].push_back({j,i+n,a});
		sort(es1[i].begin(),es1[i].end(),cmp);
	}
	for(int i=0;i<(1<<k);++i)for(int j=1;j<(1<<k);j<<=1)if(!(i&j))c[i|j]=c[i]+c[j];
	dp[0]=slv(es);long long ans=4e18;
	for(int i=0;i<(1<<k);++i){
		ans=min(ans,dp[i].second+c[i]);
		for(int j=1;j<=k;++j)if(!(i>>(j-1)&1)&&!vis[i|1<<(j-1)]){
			vis[i|1<<(j-1)]=1;
			bs tmp;tmp.resize(dp[i].first.size()+es1[j].size());
			merge(dp[i].first.begin(),dp[i].first.end(),es1[j].begin(),es1[j].end(),tmp.begin(),cmp);
			dp[i|1<<(j-1)]=slv(tmp);
		}
	}
	cout<<ans<<'\n';
	return 0;
}