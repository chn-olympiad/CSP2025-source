#include<bits/stdc++.h>

#define For(i,j,k) for(ll i=(j);i<=(k);i++)
#define Fol(i,j,k) for(ll i=(j);i>=(k);i--)
#define vi vector<ll>
#define pi pair<ll,ll>
#define se second
#define fi first
#define ll long long
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb push_back

using namespace std;

#define N 1000005

ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0' || ch>'9')f=(ch=='-'?-1:f),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
void write(ll x){
	if(x<0)x=-x,putchar('-');
	if(x/10)write(x/10);
	putchar(x%10+'0');
}

struct edg{
	ll u,v,w,id;
	edg(ll u=0,ll v=0,ll w=0,ll id=0):u(u),v(v),w(w),id(id){}
}E2[N],E[N];

struct Union{
	ll f[N];
	ll init(ll n){For(i,1,n)f[i]=i;}	
	ll find(ll x){return (x==f[x]?x:f[x]=find(f[x]));}
	void merge(ll x,ll y){f[x]=y;}
}U;

ll c[N];

int main(){
	double st=clock();
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ll n=read(),m=read(),k=read(),tot=0;
	For(i,1,m)E[i].u=read(),E[i].v=read(),E[i].w=read(),E[i].id=0;
	sort(E+1,E+m+1,[](edg x,edg y){return x.w<y.w;});U.init(n);
	For(i,1,m){
		ll u=U.find(E[i].u),v=U.find(E[i].v);
		if(u==v)continue;
		E2[++tot]=E[i];U.merge(u,v);
	}
	For(i,1,k){
		c[i]=read();
		For(j,1,n){ll w=read();E2[++tot]=edg(n+i,j,w,i);}
	}
	sort(E2+1,E2+tot+1,[](edg x,edg y){return x.w<y.w;});
	ll ans=1e18;
	For(S,0,(1<<k)-1){
		U.init(n+k);
		ll nowans=0;
		For(i,1,k)if(S&(1<<(i-1)))nowans+=c[i];
		For(i,1,tot){
			if(E2[i].id && (!(S&(1<<(E2[i].id-1)))))continue;
			ll u=U.find(E2[i].u),v=U.find(E2[i].v);
			if(u==v)continue;nowans+=E2[i].w;
			U.merge(u,v);
		}
		ans=min(ans,nowans);
	}
	//cerr<<(clock()-st)*1.0/CLOCKS_PER_SEC*1000<<"ms"<<endl;
	write(ans);putchar('\n');
	return 0;
}
