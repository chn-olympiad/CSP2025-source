#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f3f3f3f3f
#define N 100050
#define M 2000005
#define quickly ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
struct bcj{
	ll f[N],len;
	void init(ll a){
		for(int i=1;i<=a;i++)
			f[i]=i;
		len=a;
	}
	ll Find(ll a){
		if(a==f[a]) return a;
		f[a]=Find(f[a]);
		return f[a];
	}
	void add(ll a,ll b){
//		ll a_1=Find(a),b_1=Find(b);
		f[f[a]]=f[b];
	}
	bool same(ll a,ll b){
		return Find(a)==Find(b);
	}
}a;
ll n,m,cnt,ans,k,u[M],v[M],w[M],t[15],p[15][N],x[N],q[15],minn;
struct road{
	ll u,v,w;
}edg[M],edg1[M];
bool cmp(road a,road b){
	return a.w<b.w;
}
void kru(ll n,ll m){
	ans=cnt=0;
	for(int i=1;i<=m;i++){
		edg1[i].u=edg[i].u;
		edg1[i].v=edg[i].v;
		edg1[i].w=edg[i].w;
	}
	sort(edg1+1,edg1+m+1,cmp);
	a.init(n);
	for(int i=1;i<=m;i++){
		if(!a.same(edg1[i].u,edg1[i].v)){
			a.add(edg1[i].u,edg1[i].v);
			cnt++;
			ans+=edg1[i].w;
		}
	}
	if(cnt!=n-1) {cout<<"STO ORZ"<<endl;return ;}
}
void dfs(ll s,ll n,ll m,ll anss){
	if(s==k+1){
		kru(n,m);
		minn=min(minn,ans+anss);
		return ;
	}
	dfs(s+1,n,m,anss);
	for(int i=1;i<=n;i++){
		edg[m+i].u=i;edg[m+i].v=n+1;edg[m+i].w=p[s][i];
	}
	dfs(s+1,n+1,m+n,anss+t[s]);
	for(int i=1;i<=n;i++)
		edg[m+i].u=edg[m+i].v=edg[m+i].w=0;
}
int main(){
	quickly;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >>n>>m>>k;
	minn=inf;
	for(int i=1;i<=m;i++)
		cin >>edg[i].u>>edg[i].v>>edg[i].w;
	for(int i=1;i<=k;i++){
		cin >>t[i];
		ans=0;
		for(int j=1;j<=n;j++)
			cin >>p[i][j],ans+=p[i][j];
		if(t[i]==0 && ans==0){
			cout<<0<<endl;
			return 0;
		}
	}
	dfs(1,n,m,0);
	cout<<minn<<endl;
	
	return 0;
}
/*
luogu1250410ίχ 
//freopen("xxxx.in","r",stdin);
//freopen("xxxx.out","w",stdout);
feropen("xxxx.in","r",stdin);
feropen("xxxx.out","w",stdout);
freopen("xxxx.in","w",stdin);
freopen("xxxx.out","r",stdout);
stostostostostostostostostostostostostostosto ccf CCF orzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorz
slove
cin<<
cout>>
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
*/

