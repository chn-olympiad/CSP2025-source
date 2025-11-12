#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define i128 __int128
#define _rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define _per(i,a,b) for(ll i=(a);i>=(b);i--)
#define ckmax(a,b) a=max((ll)(a),(ll)(b))
#define ckmin(a,b) a=min((ll)(a),(ll)(b))
#define PII pair<int,int>
#define fi first
#define se second
#define _add(x,y) x=(((ll)(x)+(y))%mod+mod)%mod
#define _mul(x,y) x=(((ll)(x)*(y))%mod+mod)%mod
#define dbg(x) cout<<#x<<'='<<x<<'\n'
#define ptc putchar

ll rd(){
	ll res=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-f;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		res=res*10+(c-'0');
		c=getchar();
	}
	return res*f;
}
void wr(ll x){
	if(x<0) x=-x,ptc('-');
	if(x>9) wr(x/10);
	ptc(x%10+'0');
}

const int N=3e4+10,M=2e6+10;

int T=1;
int n,m,k;
int u,v,w;
int c[N];
int fa[N];
pair<ll,PII> G[M];
bool vis1[N],vis2[N],vis3[N];
ll ans;

int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

void sol(){
	n=rd(),m=rd(),k=rd();
//	_rep(i,1,m){
//		u=rd(),v=rd(),w=rd();
//		G[i]={w,{u,v}};
//		G[i]={w,{u+n,v+n}};
//	}
//	_rep(j,1,k){
//		w=c[j]=rd();
//		G[++m]={w,{2*n+j,2*n+k+j}};
//		_rep(i,1,n){
//			w=rd();
//			G[++m]={w,{2*n+j,i}};
//			G[++m]={w,{2*n+k+j,n+i}};
//		}
//	}
	_rep(i,1,m){
		u=rd(),v=rd(),w=rd();
		G[i]={w,{u,v}};
	}
	_rep(j,1,k){
		w=rd();
		_rep(i,1,n){
			w=rd();
			G[++m]={w,{n+j,i}};
		}
	}
	sort(G+1,G+m+1);
	_rep(i,1,n+k) fa[i]=i;
	_rep(i,1,m){
		u=G[i].se.fi,v=G[i].se.se,w=G[i].fi;
		if(find(u)==find(v)) continue;
//		dbg(u),dbg(v),dbg(w);
		u=find(u),v=find(v);
		fa[v]=u,ans+=w;
	}
	wr(ans);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	T=rd();
	while(T--) sol();
	return 0;
}
