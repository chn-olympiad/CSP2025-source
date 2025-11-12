#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
using namespace std;
ll read(){
	ll k=0;bool flag=1;char c=getchar_unlocked();
	while(!isdigit(c)){if(c=='-')flag=0;c=getchar_unlocked();}
	while(isdigit(c)){k=(k<<1)+(k<<3)+(c^48);c=getchar_unlocked();}
	if(flag)return k;else return -k;
}
char readc(){
	char c=getchar_unlocked();
	while(!isgraph(c))c=getchar_unlocked();
	return c;
}
string reads(){
	string str="";char c=getchar_unlocked();
	while(!isgraph(c))c=getchar_unlocked();
	while(isgraph(c)){str+=c;c=getchar_unlocked();}
	return str;
}
const int N=1e4+10;
const int M=1e6+10;
int n,m,k,fa[N],tot,e[20][N];
vector<int>g[N];
struct vill{
	ll c;
	vector<ll>e;
}c[20];
struct edge{
	int x,y;
	ll w;
	bool operator<(const edge a)const{return w<a.w;}
}a[M<<1];
vector<edge>ve;
int find(int x){
	if(fa[x]==x)return fa[x];
	return fa[x]=find(fa[x]);
}
map<edge,pli>mp;
bool vis[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		ll w=read();
		a[i]={u,v,w};
	}
	if(!k){
		sort(a+1,a+1+m,[](edge a,edge b){return a.w<b.w;});
		ll cnt=0,ans=0;
		for(int i=1;i<=m;++i){
			int fx=find(a[i].x),fy=find(a[i].y);
			if(fx==fy)continue;
			fa[fx]=fy;
			ans+=a[i].w;
			if(++cnt==n-1)break;
		}
		cout<<ans<<"\n";
		return 0;
	}
	for(int i=1;i<=k;++i){
		c[i].c=read();
		c[i].e.pb(0);
		for(int j=1;j<=n;++j)c[i].e.pb(read());
	}
	sort(a+1,a+1+m,[](edge a,edge b){return a.w<b.w;});
	ll cnt=0,ans=0;
	for(int i=1;i<=m;++i){
		int fx=find(a[i].x),fy=find(a[i].y);
		if(fx==fy)continue;
		ve.pb({a[i].x,a[i].y,a[i].w});
		fa[fx]=fy;
		ans+=a[i].w;
		if(++cnt==n-1)break;
	}
	for(edge i:ve){
		for(int j=1;j<=k;++j){
			if(c[j].e[i.x]+c[j].e[i.y]+c[j].c<=i.w){
				if(!mp.count(i)){
					mp[i]={i.w-(c[j].e[i.x]+c[j].e[i.y]+c[j].c),j};
					continue;
				}
				ll x=mp[i].fi;
				if(x>i.w-(c[j].e[i.x]+c[j].e[i.y]+c[j].c)){
					mp[i]={min(mp[i].fi,i.w-(c[j].e[i.x]+c[j].e[i.y]+c[j].c)),j};
				}
			}
		}
	}
	tot=m;
	for(auto i:mp){
		int k=i.se.se;
		for(int j=1;j<=n;++j)a[++tot]={k+n,j,c[k].e[j]};
	}
	sort(a+1,a+1+tot,[](edge a,edge b){return a.w<b.w;});
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=n+1;i<=n+k;++i)fa[i]=i;
	cnt=0;
	ll res=0;
	for(int i=1;i<=tot;++i){
		int fx=find(a[i].x),fy=find(a[i].y);
		if(fx==fy)continue;
		if(fx>fy)swap(fx,fy);
		if(fy>n){
			if(!vis[fy-n])res+=c[fy-n].c,vis[fy-n]=1;
		}
		fa[fx]=fy;
		res+=a[i].w;
		if(++cnt==n+mp.size()-1)break;
	}
	cout<<min(ans,res)<<"\n";
    return 0;
}
// -std=c++14 -O2 
