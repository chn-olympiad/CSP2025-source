#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF = 1e18;
ll n,m,k;
ll readd(){
	char c=getchar();ll f=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))f=f*10+c-'0',c=getchar();
	return f;
}void output(ll x){
	if(x>9)output(x/10);
	putchar(x%10+'0');
}
struct edge{
	ll u,v,val,typ;
};struct city{
	ll c,val[10005];
};
vector<edge> e;
city a[15];
bool vis[15];
ll bcj[11005];
ll ans = INF;
ll get_father(ll x){
	if(bcj[x]==x)return x;
	return bcj[x]=get_father(bcj[x]);
}
ll kruskal(ll num){
	for(register ll i = 0;i<=10010;++i)bcj[i]=i;
	ll cnt=0,js=0;
	ll fa,fb;
	for(auto f:e){
		if(js==n+num-1)break;
		if(!vis[f.typ])continue;
		fa=get_father(f.u),fb=get_father(f.v);
		if(fa!=fb){
			js++,cnt+=f.val,bcj[fa]=fb;
		}
	}
	return cnt;
}
void qpl(ll dep,ll cst,ll jss){
	if(dep==k+1){
		ll f=kruskal(jss);
		ans = min(ans,f+cst);
		return ;
	}
	vis[dep] = 1;
	qpl(dep+1,cst+a[dep].c,jss+1);
	vis[dep] = 0;
	qpl(dep+1,cst,jss);
	vis[dep]=0;
	return ;
}
bool cmp(edge x,edge y){
	return x.val<y.val;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=readd(),m=readd(),k=readd();
	ll u,v,w;
	for(ll i = 1;i<=m;++i){
		u=readd(),v=readd(),w=readd();
		e.push_back({u,v,w,0});
	}
	ll cnt0=0;
	bool t;
	for(ll i = 1;i<=k;++i){
		a[i].c=readd();
		t=0;
		for(register ll j = 1;j<=n;++j){
			a[i].val[j]=readd();
			if(!a[i].val[j]&&!t)cnt0++,t=1;
		}
	}
	if(cnt0==k){
		for(register ll i = 1;i<=k;++i){
			for(register ll j = 1;j<=n;++j){
				e.push_back({n+i,j,a[i].val[j],i});
			}
		}
		sort(e.begin(),e.end(),cmp);
		for(register ll i = 0;i<=k;++i)vis[i] = 1;
		output(kruskal(k));
	}else{
		for(register ll i = 1;i<=k;++i){
			for(register ll j = 1;j<=n;++j){
				e.push_back({n+i,j,a[i].val[j],i});
			}
		}
		sort(e.begin(),e.end(),cmp);
		vis[0]=1;
		qpl(1,0,0);
		output(ans);
	}
	return 0;
}
