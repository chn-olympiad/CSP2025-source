#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=(a);i<=(int)(b);i++)
using ll=long long;
const ll INF=2e18;
const int Cnt=1e4+4;
ll sum,A[14][Cnt];
int n,m,k,fa[Cnt];
struct f{
	int u,v;
	ll w;
};
vector<f> g;
vector<vector<ll> > g1(1e3+4,vector<ll>(1e3+4,INF));
bool cmp(const f a,const f b){
	return a.w<b.w;
}
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void ms(){
	int i=1;
	for(f z:g){
		if(i>n-1)break;
		if(find(z.u)!=find(z.v)){
			i++;
			fa[find(z.u)]=fa[find(z.v)];
			sum+=z.w;
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;g.resize(m);
	REP(z,1,n)fa[z]=z;
	REP(z,0,m-1){
		cin>>g[z].u>>g[z].v>>g[z].w;
		g1[g[z].u][g[z].v]=min(g[z].w,g1[g[z].u][g[z].v]);
		g1[g[z].v][g[z].u]=min(g[z].w,g1[g[z].v][g[z].u]);
	}
	int flag=1;
	REP(z,1,k){
		cin>>A[z][0];
		if(A[z][0])flag=0;
		REP(i,1,n)cin>>A[z][i];
	}
	if(!flag){
		sort(g.begin(),g.end(),cmp);
		ms();
		cout<<sum;
		return 0;
	}
	g.clear();
	REP(z,1,n)REP(i,1,n)REP(j,1,k)g1[z][i]=min(g1[z][i],A[j][z]+A[j][i]);
	REP(z,1,n)REP(i,1,n)g.push_back(f{z,i,g1[z][i]});
	sort(g.begin(),g.end(),cmp);
	ms();
	cout<<sum;
	return 0;
}