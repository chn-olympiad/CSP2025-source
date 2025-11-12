#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e5+50;
void rd(){}
template<typename T,typename ...U>
void rd(T &x,U &...args){
	x=0;T f=1;int ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	x*=f;rd(args...); 
}
int n,m,k,c[N],a[12][N],fa[N],deg[N],tmp[N];
struct Edge{
	int u,v,w;
	bool operator < (const Edge it) const {
		return w<it.w;
	}
};
vector<Edge>e,lk[12];
inline int get(int x){
	if(fa[x]==x)return x;
	return fa[x]=get(fa[x]);
}
void solve1(){
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			e.push_back({n+i,j,a[i][j]});
		}
	}
	for(int i=1;i<=n+k;i++)fa[i]=i;
	sort(e.begin(),e.end());
	int cnt=0,res=0;
	for(auto it:e){
		int u=it.u,v=it.v,w=it.w;
		int fx=get(u),fy=get(v);
		if(fx==fy)continue;
		fa[fx]=fy;
		res+=w;
		deg[u]++,deg[v]++;
		tmp[u]=tmp[v]=w;
		if(++cnt==n+k-1)break;
	}
	for(int i=n+1;i<=n+k;i++){
		if(deg[i]==1)res-=tmp[i];
	}
	printf("%lld",res);
}
void solve2(){
	for(int i=1;i<=n+k;i++)fa[i]=i;
	sort(e.begin(),e.end());
	int cnt=0,res=0;
	for(auto it:e){
		int u=it.u,v=it.v,w=it.w;
		int fx=get(u),fy=get(v);
		if(fx==fy)continue;
		fa[fx]=fy;
		res+=w;
		if(++cnt==n+k-1)break;
	}
	printf("%lld",res);
}
inline vector<Edge> merge(vector<Edge>l,vector<Edge>r){
	vector<Edge>cur;
	int x=0,y=0;
	for(;x<l.size()&&y<r.size();){
		if(l[x]<r[y])cur.push_back(l[x]),x++;
		else cur.push_back(r[y]),y++;
	}
	while(x<l.size())cur.push_back(l[x]),x++;
	while(y<r.size())cur.push_back(r[y]),y++;
	return cur;
} 
void solve3(){
	int ans=1e18;
	for(int i=1;i<=n+k;i++)fa[i]=i;
	sort(e.begin(),e.end());
	auto t=e;
	for(int s=0;s<1<<5;s++){
		e=t;vector<Edge>tp;
		int kk=0,res=0;
		for(int i=1;i<=k;i++){
			if(!(s>>(i-1)&1))continue;
//			for(auto it:lk[i])e.push_back(it);
			tp=merge(tp,lk[i]);
			kk++;res+=c[i];
		}
		if(res>=ans)continue;
		e=merge(e,tp);
		for(int i=1;i<=n+k;i++)fa[i]=i,deg[i]=0,tmp[i]=0;
		sort(e.begin(),e.end());
		int cnt=0;
		for(auto it:e){
			int u=it.u,v=it.v,w=it.w;
			int fx=get(u),fy=get(v);
			if(fx==fy)continue;
			fa[fx]=fy;
			res+=w;
			deg[u]++,deg[v]++;
			tmp[u]=tmp[v]=w;
			if(++cnt==n+kk-1)break;
		}
		for(int i=n+1;i<=n+k;i++){
			if(deg[i]==1)res-=tmp[i];
		}
		ans=min(ans,res);
//		cerr<<ans<<' '<<s<<'\n';
	}
	printf("%lld",ans);
}
#undef int 
int main(){
#define int long long 
//	ios::sync_with_stdio(0),cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	cin>>n>>m>>k;
	rd(n,m,k);
	for(int i=1;i<=m;i++){
		int x,y,w;rd(x,y,w);
		e.push_back({x,y,w});
	}
	bool all=1;
	for(int i=1;i<=k;i++){
		rd(c[i]);
		if(c[i]!=0)all=0;
		for(int j=1;j<=n;j++)cin>>a[i][j],lk[i].push_back({n+i,j,a[i][j]});
		sort(lk[i].begin(),lk[i].end());
	}
	if(all)solve1(); 
	else if(!k)solve2();
	else solve3();
	
	return 0;
} 
