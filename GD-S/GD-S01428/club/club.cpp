#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define se second
#define fi first
using namespace std;
template<typename T> inline void read(T &x){
	x=0;
	T w=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') w=-1;
		c=getchar();
	}
	while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
	x*=w;
}
template<typename T> inline void write(T x){
	if(x<0) putchar('-'),x=(~x)+1;
	if(x>9) write(x/10);
	putchar(x%10^48);
}
const ll N=1e5+10;
struct data{
	pll a[4];
}d[N];
bool cmp2(data x,data y){
	return max(x.a[1].fi,max(x.a[2].fi,x.a[3].fi))>max(y.a[1].fi,max(y.a[2].fi,y.a[3].fi));
}
ll n;
priority_queue<ll>q[4];
void solve(){
	read(n);
//	cout<<n<<"\n";
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			read(d[i].a[j].first);
			d[i].a[j].second=j;
		}
//		sort(d[i].a+1,d[i].a+4,cmp);
	}
	sort(d+1,d+n+1,cmp2);
	ll ans=0;
	for(int i=1;i<=n;i++){
		pll t=max(d[i].a[1],max(d[i].a[2],d[i].a[3]));
		ll id=t.se;
		if(id==1){
			ll g=max(d[i].a[2].fi-d[i].a[1].fi,d[i].a[3].fi-d[i].a[1].fi);
			q[id].push(g);
		}
		if(id==2){
			ll g=max(d[i].a[1].fi-d[i].a[2].fi,d[i].a[3].fi-d[i].a[2].fi);
			q[id].push(g);
		}
		if(id==3){
			ll g=max(d[i].a[1].fi-d[i].a[3].fi,d[i].a[2].fi-d[i].a[3].fi);
			q[id].push(g);
		}
		ans+=t.fi;
		if(q[id].size()>n/2) ans+=q[id].top(),q[id].pop();
	}
	write(ans);
	putchar('\n');
	for(int i=1;i<=3;i++){
		while(q[i].size()) q[i].pop();
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	read(T);
	while(T--) solve();
	return 0;
}
/*
Àä¾² 
*/
