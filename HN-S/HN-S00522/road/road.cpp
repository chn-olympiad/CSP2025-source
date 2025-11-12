#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,r,l) for(int i=(r);i>=(l);i--)
#define N 1100010
int n,m,k,c[N],ans=1e16;
bool del[N];
struct dsu{
	int fa[N],siz[N];
	void init(int lim){rep(i,1,lim){fa[i]=i;siz[i]=1;}}
	int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
	void merge(int x,int y){
		x=find(x);y=find(y);
		if(x==y){return;}
		if(siz[x]<siz[y]){swap(x,y);}
		fa[y]=x;siz[x]+=siz[y];
	}
}ds;
struct stu{
	int u,v,w;
	friend bool operator<(stu a,stu b){
		return a.w<b.w;
	}
}eg[N];
int calc(int S){
	int ss=0,nums=n,tt=0;
	rep(i,n+1,n+k){del[i]=0;}
	rep(i,1,k){if(!(S&(1<<(i-1)))){del[i+n]=1;}else{ss+=c[i];nums++;}}
	ds.init(n+k);
	rep(i,1,m+k*n){
		int u=eg[i].u,v=eg[i].v,w=eg[i].w;
		if(del[u]||del[v]){continue;}
		if(ds.find(u)==ds.find(v)){continue;}
		ss+=w;ds.merge(u,v);tt++;
		if(tt==(nums-1)){break;}
	}
	return ss;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>k;
	rep(i,1,m){cin>>eg[i].u>>eg[i].v>>eg[i].w;}
	rep(i,1,k){
		cin>>c[i];
		rep(j,1,n){
			int x;cin>>x;eg[m+(i-1)*n+j].u=i+n;eg[m+(i-1)*n+j].v=j;eg[m+(i-1)*n+j].w=x;
		}
	}
	sort(eg+1,eg+m+k*n+1);
	rep(S,0,(1<<k)-1){ans=min(ans,calc(S));}
	cout<<ans;return 0;
}
