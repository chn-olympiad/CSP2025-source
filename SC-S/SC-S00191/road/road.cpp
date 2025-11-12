#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+4,M=1e6+6,mod=998244353;
const ll INF=1e18;
#define rep(i,l,r)	for(int i=(l);i<=(r);i++)
#define atrep(i,l,r)	for(int i=(r);i>=(l);i--)
bool Beg; 
struct node{
	int x,y;
	ll z;
	bool vis;
	friend bool operator <(node p,node q){
		return p.z<q.z;
	}
}g[M];
multiset<node>se;
int fa[N];
int find(int x){
	if(fa[x]==x)	return x;
	return fa[x]=find(fa[x]);
}
int c[N];
int a[12][N];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.in","w",stdout);
	ios::sync_with_stdio(0);
	int n,m,k;
	cin>>n>>m>>k;
	rep(i,1,m){
		cin>>g[i].x>>g[i].y>>g[i].z;
	}
	sort(g+1,g+m+1);
	rep(i,1,n){
		fa[i]=i;
	}
	ll res=0;
	ll maxn=0;
	rep(i,1,m){
		int x=find(g[i].x),y=find(g[i].y);
		if(x==y)	continue;
		g[i].vis=1;
		se.insert(g[i]);
		maxn=max(maxn,g[i].z);
		fa[x]=y;
		res+=g[i].z;
	}
	rep(i,1,k){
		cin>>c[i];
		rep(j,1,n){
			cin>>a[i][j];	
		}
	}
	rep(S,1,(1<<k)-1){
		ll tmp=0;
		int bb=__builtin_popcount(S);
		rep(i,1,k){
			if((S>>(i-1))&1){
				tmp+=c[i];
			}
		}
		if(tmp>res)	continue;
		rep(i,1,n+k)	fa[i]=i;	
		rep(i,1,k){
			if(((S>>(i-1))&1)){
				rep(j,1,n){
					if(a[i][j]<maxn)
						se.insert({i+n,j,a[i][j],0});
				}
			}
		}
		int sz=0;
		for(auto it:se){
			int x=it.x,y=it.y,z=it.z;
			if(x==y){
				continue;
			}
			x=find(x),y=find(y);
			if(x==y)	continue;
			tmp+=z;sz++;
			if(tmp>res)	break;
			fa[x]=y;
			if(sz==n+bb-1)	break;
		}
		res=min(res,tmp);
		rep(i,1,k){
			if(((S>>(i-1))&1)){
				rep(j,1,n){
					if(a[i][j]<maxn)
						se.erase({i+n+1,j,a[i][j],0});
				}
			}
		}
	}	
	cout<<res<<endl;
}
/*
枚举每个乡镇选或不选
诶诶诶你怎么被骗了。

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/