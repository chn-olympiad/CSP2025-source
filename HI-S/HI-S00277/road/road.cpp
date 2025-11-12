#include<bits/stdc++.h>
#define ll long long
#define db double
#define pii pair<ll,ll>
#define pll pair<ll,ll>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define grep(i,u) for(int i=hd[(u)];i;i=E[i].nx)
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int ll

using namespace std;
bool STA_MEMORY;

int n,m,ans,k,q;
const int N=2e4+10,M=3e6+10,mod=998244353;

int c[12],p[N],If[12];

struct node{
	int u,v,w,nx;
	bool operator>(const node b)const{
		return w==b.w?u>b.u:w>b.w;
	}
	bool operator<(const node b)const{
		return w==b.w?u<b.u:w<b.w;
	}
}E[M];
int hd[N],K;
void add(int u,int v,int w){
	E[++K]={u,v,w,hd[u]};
	hd[u]=K;
}

priority_queue<node,vector<node>,greater<node> > pq;

void prim(){
	p[1]=1;
	grep(i,1){
		pq.push(E[i]);
	}
	
	while(!pq.empty()){
		node b=pq.top();
		pq.pop();
		if(p[b.v]==1) continue;
//		cerr<<b.u<<' '<<b.v<<'\n';
		p[b.v]=1;
		ans+=b.w;
		if(b.u>n+10) If[b.u-n-10]=0;
		if(b.v>n && b.v<=n+10) If[b.v-n]=b.w+c[b.v-n];
		grep(i,b.v){
			pq.push(E[i]);
		}
	}
	
	rep(i,1,k){
		ans-=If[i];
		cerr<<If[i]<<'\n';
	}
}

void solve(){
	cin>>n>>m>>k;
	rep(i,1,m){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	rep(i,1,k){
		cin>>c[i];
		add(n+i,n+10+i,c[i]);
		rep(j,1,n){
			int w;cin>>w;
			add(j,n+i,w);
			add(n+10+i,j,w);
		}
	}
	prim();
	
	cout<<ans<<'\n';
}

bool END_MEMORY;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	fastIO;
	
	int c,T=1;
	//cin>>T;
	while(T--){
		solve();
	}
	
	cerr<<"\n\nMemory:  "<<(&END_MEMORY-&STA_MEMORY)/1048576<<"  MB\n";
	return 0;
}

