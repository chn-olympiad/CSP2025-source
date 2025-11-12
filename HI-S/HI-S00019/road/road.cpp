#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define ull unsigned long long
#define N 20010
#define For(i,a,b) for(register int i=a;i<=b;++i)
#define Rof(i,a,b) for(register int i=a;i>=b;--i)
#define ls x<<1
#define rs x<<1|1
#define lson ls,l,mid
#define rson rs,mid+1,r
#define pb push_back
#define mk make_pair
#define pque priority_queue
#define pii pair<ll,ll>
#define fi first
#define se second

using namespace std;
struct node{
	int u,v,bh;
	ll w;
}a[1200010],b[1200010];
ll d[12][N],c[12];
int n,m,q,tot;

ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int f[N];
int gf(int x){
	if(f[x]==x) return x;
	return f[x]=gf(f[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),q=read();
	For(i,1,m){
		a[i].u=read(),a[i].v=read(),a[i].w=read();
	}
	sort(a+1,a+m+1,[&](node x,node y){return x.w<y.w;});
	For(i,1,n) f[i]=i;
	For(i,1,m){
		int u=gf(a[i].u),v=gf(a[i].v);
		if(u!=v) f[v]=u,b[++tot]=a[i];
	}
	For(i,1,q){
		c[i]=read();
		For(j,1,n) d[i][j]=read();
		For(j,1,n){
			b[++tot]=(node){n+i,j,i,d[i][j]};
		}
	}
	sort(b+1,b+tot+1,[&](node x,node y){return x.w<y.w;});
	ll ans=1e18;
	For(S,0,(1<<q)-1){
		int len=__builtin_popcount(S);
		ll now=0;
		For(i,0,q-1) if((S>>i)&1) now+=c[i+1];
		For(i,1,n+q) f[i]=i;
		int cnt=0;
		For(i,1,tot){
			if(cnt==n+len-1) break;
			if(now>=ans) break;
			if(b[i].bh && !((S>>(b[i].bh-1)&1))) continue;
			int u=gf(b[i].u),v=gf(b[i].v);
			if(u!=v){
				cnt++;
				f[v]=u;
				now+=b[i].w;
			}
		}
		if(cnt==n+len-1) ans=min(ans,now);
	}
	cout<<ans;
	return 0;
}
