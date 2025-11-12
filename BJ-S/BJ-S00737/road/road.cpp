#include<bits/stdc++.h>
#define F(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define dF(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
#define rep(i,a,b,c) for(int i=(a);i<=(b);i+=(c))
#define per(i,a,b,c) for(int i=(a);i>=(b);i-=(c))
#define ll long long
#define uint unsigned
#define ull unsigned long long
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define mkp make_pair
#define fi first
#define se second
#define pii pair<int,int>
#define pb push_back
#define eb emplace_back
#define lowbit(x) ((x)&(-(x)))
using namespace std;
bool ST;
template<typename T>inline void chkmax(T &x,const T y){ x=max(x,y); }
template<typename T>inline void chkmin(T &x,const T y){ x=min(x,y); }
const int inf=1000000005;
const ll infll=1000000000000000005ll;
const int maxn=10015;
void fre(){
	freopen("road.in","r",stdin),freopen("road.out","w",stdout);
}
int n,zsy,k,fa[maxn],c[12],a[12][maxn];
inline int find(int x){ return fa[x]==x?x:fa[x]=find(fa[x]); }
vector<array<int,3>>qwq[12],S[1105];
void Solve_(){
	cin>>n>>zsy>>k;
	vector<array<int,3>>E,nxt;
	F(_,1,zsy){ int u,v,w;cin>>u>>v>>w,E.push_back({w,u,v}); }
	F(i,1,k){
		cin>>c[i];
		F(j,1,n)cin>>a[i][j],qwq[i].push_back({a[i][j],i+n,j});
		sort(all(qwq[i]));
	}
	sort(all(E));
	F(i,1,n)fa[i]=i;
	ll ans=0;
	F(_,0,SZ(E)-1){
		const int u=E[_][1],v=E[_][2],w=E[_][0],x=find(u),y=find(v);
		if(x==y)continue;
		fa[x]=y,ans+=w,nxt.push_back(E[_]);
	}
	if(!k)return cout<<ans<<'\n',void();
	S[0]=nxt;
	F(s,1,(1<<k)-1){
		ll sum=0;
		F(i,1,k)if((s>>(i-1))&1)sum+=c[i];
		F(i,1,n+k)fa[i]=i;
		vector<array<int,3>>nw,e;
		int pos=0;
		F(i,1,k)if((s>>(i-1))&1)pos=i;
		nw.resize(n+SZ(S[s^(1<<(pos-1))]));
		merge(all(qwq[pos]),all(S[s^(1<<(pos-1))]),nw.begin());
		e.swap(nw),nw.clear();
		F(_,0,SZ(e)-1){
			int u=find(e[_][1]),v=find(e[_][2]);
			if(u==v)continue;
			sum+=e[_][0],fa[v]=u,nw.push_back(e[_]);
		}
		S[s]=nw,chkmin(ans,sum);
	}
	cout<<ans<<'\n';
}
bool ED;
signed main(){
	fre(),ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int zsy=1;
	F(_,1,zsy)Solve_();
}
// g++ road.cpp -o a -std=c++14 -O2 -Wall -Wextra