#include<bits/stdc++.h>
#define pii pair<ll,ll>
#define ll long long 
using namespace std;
void read(ll &x){
	char c=getchar();x=0;
	ll fh=1;
	while('0'>c||c>'9'){
		if(c=='-') fh*=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9') x=x*10-48+c,c=getchar();
	x*=fh;
}
void write(ll x){
	if(x<0) {
		putchar('-');
		x*=-1;
	}
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}
const int N=1e4+5,M=1e6+5,K=15;
ll n,m,k,fa[N+K],h[N+K],ans,cnt[N+K],num,minn=1e18,c[K];
struct NODE{
	ll u,v,w;
	bool operator<(const NODE&x)const{
		return w>x.w;
	}
}a[M],bj[K][N];
vector<NODE> sz;
ll find(ll x){
	if(fa[x]!=x)return fa[x]=find(fa[x]);
	else return x;
}
ll merge(ll x,ll y){
	if(find(x)==find(y)) return 0;
	ll zx=find(x),zy=find(y);
	if(h[zx]>h[zy]) zx^=zy^=zx^=zy;
	fa[zx]=zy;
	if(h[zx]==h[zy]) h[zy]++;
	return 1;
}
bool cmp(NODE x,NODE y) {return x.w<y.w;}
vector<NODE> sl;
priority_queue<NODE> q;
vector<ll> sll;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n),read(m),read(k);
	for(ll i=1,u,v,w;i<=m;i++){
		read(u),read(v),read(w);
		a[i]={u,v,w};
	}
	sort(a+1,a+m+1,cmp);
	for(ll i=1;i<=k;i++){
		cin>>c[i];
		for(ll j=1,v;j<=n;j++)read(v),bj[i][j]={i+n,j,v};
		sort(bj[i]+1,bj[i]+n+1,cmp);
	}

		for(ll i=1;i<=n+k;i++)fa[i]=i,h[i]=1;
		for(ll i=1;i<=m;i++){
//			cout<<a[i].u<<' '<<a[i].v<<' '<<a[i].w<<'\n';
			if(find(a[i].u)==find(a[i].v)) continue;
			merge(a[i].u,a[i].v);
			ans+=a[i].w;
		}
//		cout<<ans<<'\n';
		minn=min(minn,ans);
		for(ll i=1;i<=(1<<k)-1;i++){
			sll.clear(),ans=0,sz.clear(),sl.clear(),num=0;
			memset(cnt,0,sizeof cnt);
			while(!q.empty())q.pop();
			for(ll j=0;j<k;j++){
				if(i&(1<<j)) {
					ll tmp=j+1;
					++num;
					ans+=c[tmp];
					sll.push_back(tmp);
				}
			}
			for(auto j:sll){
//				cout<<j<<'\n';
				q.push({bj[j][1]});
				cnt[j]=1;
			}
			while(!q.empty()){
				NODE tmp=q.top();
//				cout<<tmp.u<<' '<<tmp.v<<' '<<tmp.w<<'\n';
				q.pop();
				sl.push_back(tmp);
				cnt[tmp.u-n]++;
				if(cnt[tmp.u-n]>n) continue;
				if(cnt[tmp.u-n]<=n) q.push(bj[tmp.u-n][cnt[tmp.u-n]]);
			}
//			for(auto j:sl){
//				cout<<j.u<<' '<<j.v<<' '<<j.w<<'\n';
//			}
			ll l=1;
			for(ll j=1;j<=n+k;j++)fa[j]=j,h[j]=1;
			for(auto j:sl){
//				cout<<j.u<<' '<<j.v<<' '<<j.w<<'\n';
				while(l<=m&&j.w>=a[l].w) {
					if(merge(a[l].u,a[l].v))ans+=a[l].w;
					++l;
				}
				if(merge(j.u,j.v))ans+=j.w;
			}
//			cout<<ans<<'\n';
			minn=min(minn,ans);
		}
		cout<<minn;
	return 0;
}
/*
5 6 0
1 2 4
1 3 3
1 5 2
2 4 3
2 3 9
3 5 2
*/