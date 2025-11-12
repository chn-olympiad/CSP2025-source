#include <bits/stdc++.h>
#define ll long long
#define pii array<ll,2>
using namespace std;
ll read(){
	ll s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=s*10+(ch-'0');
		ch=getchar();
	}
	return s*f;
}
ll n,m,k;
struct edge{
	ll u,v,w;
	friend bool operator <(const edge &a,const edge &b){
		return a.w<b.w;
	}
}a[1000020],b[1000020],c[1000020];
ll f[20100],ans,val[20],s[15][20020];
ll find(ll u){return u==f[u]?u:f[u]=find(f[u]);}
ll kruscal(ll N,ll M,bool op=0){
	sort(c+1,c+1+M);
	for(ll i=1;i<=N;i++) f[i]=i;
	ll res=0,m_=0;
	for(ll i=1,u,v;i<=M;i++){
		u=find(c[i].u),v=find(c[i].v);
		if(u==v) continue;
		if(op) b[++m_]=c[i];
		else ++m_;
		res+=c[i].w,f[v]=u;
	}
	return res;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	// clock_t st=clock();
	n=read(),m=read(),k=read();
	for(ll i=1;i<=m;i++)
		a[i].u=read(),a[i].v=read(),a[i].w=read(),c[i]=a[i];
	ans=kruscal(n,m,1);
	for(ll i=1;i<=k;i++){
		val[i]=read();
		for(ll j=1;j<=n;j++)
			s[i][j]=read();
	}
	for(ll S=0,M,res,N;S<1ll<<k;S++){
		M=res=0,N=n;
		for(ll i=1;i<n;i++) c[++M]=b[i];
		for(ll i=1;i<=k;i++)
			if(S>>(i-1)&1){
				res+=val[i],N++;
				for(ll j=1;j<=n;j++)
					c[++M]={N,j,s[i][j]};
			}
		ans=min(ans,res+kruscal(N,M));
	}
	printf("%lld\n",ans);
	// fprintf(stderr,"%.2lf\n",(clock()-st)*1.0/CLOCKS_PER_SEC);
	return 0;
}
//g++ road.cpp -o road -std=c++14 -O2 -Wall -Wextra -fno-ms-extensions