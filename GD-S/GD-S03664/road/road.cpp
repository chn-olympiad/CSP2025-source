#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e6+10,M=2e5+10;
struct Node{
	ll u,v,w,idx;
}e[N],G[N];
vector<int> c[N];
bool cmpp(vector<int> x,vector<int> y){
	return x[0]<y[0];
}
ll a[N],fa[N],d[N],res=1e14;
ll n,m,m_,k;
int findp(int x){
	return x==fa[x] ? x : fa[x]=findp(fa[x]);
}
bool cmp(Node x,Node y){
	if(x.w==y.w) return x.u<y.u;
	return x.w<y.w;
}
ll kru(ll len,ll sum,int k_){
	ll ret=sum,cnt=0;
	sort(e+1,e+len+1,cmp);
	for(int i=1;i<=n+k;i++) fa[i]=i,d[i]=0;
	int tt=0;
	for(int i=1;i<=len;i++){
		int u=e[i].u,v=e[i].v;
		int fu=findp(u),fv=findp(v);
		if(fu==fv) continue;
		fa[fu]=fv;
		d[u]++;d[v]++;
		cnt++;ret+=e[i].w;
		if(u>n||v>n) G[++tt]=e[i];
		if(cnt==n+k_-1) break;
	}
	for(int i=n+1;i<=n+k_;i++)
		if(d[i]<=1) ret-=a[i-n];
	for(int i=1;i<=tt;i++)
		if(d[G[i].u]<=1) ret-=G[i].w;
	return ret;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m_>>k;
	for(int i=1;i<=m_;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		e[i]={u,v,w,i};
	}
	m=m_;
	res=kru(m,0,0);
	ll sum=0;
	for(int i=1;i<=k;i++){
		c[i].resize(n+1);
		cin>>c[i][0];
		for(int j=1;j<=n;j++)
			cin>>c[i][j];
	}
	sort(c+1,c+1+k,cmpp);
	for(int i=1;i<=k;i++){
		sum+=c[i][0]; a[i]=c[i][0];
		for(int j=1;j<=n;j++)
			e[++m]={i+n,j,c[i][j]};
		ll tem=kru(m,sum,i);
//		cout<<a[i]<<" "<<tem<<"\n";
		res=min(res,tem);
	}
	cout<<res<<"\n";
	return 0;
}
