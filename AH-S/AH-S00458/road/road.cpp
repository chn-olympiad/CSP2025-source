#include<bits/stdc++.h>
#define for1(i,a,b) for(int i = (a);(i) <= (b);++(i))
#define for2(i,a,b) for(int i = (a);(i) >= (b);--(i))
#define pb push_back
#define pf push_front
using namespace std;
template<typename T> T cmax(T &x,T y){if(x < y) x = y;}
template<typename T> T cmin(T &x,T y){if(x > y) x = y;}
typedef long long LL;
typedef unsigned long long ULL;
#define int long long
typedef pair<int,int> P;
const int N = 1e4 + 15;
const int M = 1e4 + 15;
const int MOD = 10007;
int n,m,k;
vector<P> g[N];
vector<P> g1[N];
LL c[15],ans,ans1;
struct node{
    int w,v,fr;
    bool operator >(const node tmp)const{
        return (w==tmp.w)?(v>tmp.v):(w>tmp.w);
    }
};
priority_queue<node,vector<node>,greater<node> > q,q1;
LL d[N],cnt;
bool vis[N];
LL din[15];
LL a[15][N];
bool dout[15];
void prim(){
	for1(i,1,n+k)d[i]=(int)1e18+5;
	for1(i,1,n+k)vis[i]=0;
	for1(i,1,k) din[i]=dout[i]=0;
	d[1]=cnt=0;
	q.push(node{0,1,-114514});
	while(!q.empty()){
		node t=q.top(); q.pop();
		LL dis=t.w,u=t.v;
		if(vis[u]) continue;
		vis[u]=1;
		ans+=dis;
		//cout<<dis<<" "<<u<<"\n";
		if(u<=n){
			cnt++;
			if(t.fr>n){
                dout[t.fr-n]=1;
			}
			if(cnt==n) break;
		}else{
            din[u-n]=t.fr;
		}
		for(P t2:g[u]){
			LL v=t2.first,w=t2.second;
			//cout<<v<<" "<<d[v]<<"\n";
			if(d[v]>w){
				d[v]=w;
				//cout<<v<<"\n";
				q.push(node{d[v],v,u});
			}
		}
	}
}
void prim1(){
	for1(i,1,n+k)d[i]=(int)1e18+5;
	for1(i,1,n+k)vis[i]=0;
	d[1]=cnt=0;
	q1.push(node{0,1,-114514});
	while(!q1.empty()){
		node t=q1.top(); q1.pop();
		LL dis=t.w,u=t.v;
		if(vis[u]) continue;
		vis[u]=1;
		ans1+=dis;
		if(u<=n){
			cnt++;
			if(cnt==n) break;
		}
		for(P t2:g1[u]){
			LL v=t2.first,w=t2.second;;
			if(d[v]>w){
				d[v]=w;
				q1.push(node{d[v],v,u});
			}
		}
	}
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
//	cin>>n>>m>>k;
	scanf("%lld",&n);
	scanf("%lld",&m);
	scanf("%lld",&k);
	LL u,v,w;
	for1(i,1,m){
        scanf("%lld",&u);
        scanf("%lld",&v);
        scanf("%lld",&w);
		g[u].pb(P{v,w});
		g[v].pb(P{u,w});
		g1[u].pb(P{v,w});
		g1[v].pb(P{u,w});
	}
	for1(i,1,k){
		//cin>>c[i];
        scanf("%lld",&c[i]);
		for1(j,1,n){
			//cin>>a[i][j];
            scanf("%lld",&a[i][j]);
			g[j].pb(P(i+n,c[i]+a[i][j]));
			g[n+i].pb(P(j,a[i][j]));
		}
	}
	prim1();
	prim();
	for1(i,1,k){
        if(vis[n+i]){
            if(dout[i]) continue;
            ans-=a[i][din[i]]+c[i];
        }
	}
	//cout<<ans1<<"\n";
	cout<<min(ans,ans1);
    return 0;
}
/*
6 7 0
1 2 100
1 3 100
1 4 1
2 4 1
4 6 1
5 6 1
4 5 100
*/
