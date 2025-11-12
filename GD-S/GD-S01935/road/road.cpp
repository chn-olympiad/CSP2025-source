#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k;
bool A_flag=1;
ll ans=LLONG_MAX,sum;
struct edg{
	ll u,v,w;
	bool operator <(const edg b)const{
		return w<b.w;
	}
}road[5000007];
ll cnt;
ll ct[27];
ll p[100007];
ll findp(ll x){
	if(!p[x]) return x;
	p[x]=findp(p[x]);
	return p[x];
}
void merge(ll x,ll y){
	ll px=findp(x);
	ll py=findp(y);
	if(px==py) return;
	p[px]=py;
	return;
}
bool check(ll x,ll y){
	ll px=findp(x);
	ll py=findp(y);
	return (px==py);
}
void add(ll x,ll y,ll w){
	cnt++;
	road[cnt].u=x;
	road[cnt].v=y;
	road[cnt].w=w;
}
bool chk(ll u,ll i){
	if(u<=n) return 0;
	u-=n;
	if((i|(1<<(u-1)))==i) return 0;
	return 1;
}
void init(){
	sum=0;
	for(int i=1;i<=n+k;i++) p[i]=0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		ll x,y,w;
		cin>>x>>y>>w;
		add(x,y,w);
		add(y,x,w);
	}
	for(int i=1;i<=k;i++){
		cin>>ct[i];
		if(ct[i]!=0) A_flag=0;
		for(int j=1;j<=n;j++){
			ll w;
			cin>>w;
			add(n+i,j,w);
			add(j,n+i,w);
		}
	}
	sort(road+1,road+cnt+1);
	if(A_flag){
		init();
		for(int i=1;i<=cnt;i++){
			edg t=road[i];
			if(check(t.u,t.v)) continue;
			sum+=t.w;
			merge(t.u,t.v);
		}
		ans=sum;
		cout<<ans;
		return 0;
	}
	for(int i=0;i<=((1<<k)-1);i++){
		init();
		for(int j=0;(1<<j)<=i;j++){
			if((i|(1<<j))==i) sum+=ct[j+1];
		}
		for(int j=1;j<=cnt;j++){
			edg t=road[j];
			if(chk(t.u,i)||chk(t.v,i)) continue;
			if(check(t.u,t.v)) continue;
			sum+=t.w;
			merge(t.u,t.v);
		}
		ans=min(ans,sum);
	}
	cout<<ans;
	return 0;
} 
