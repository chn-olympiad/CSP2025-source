#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;++i)
#define Rof(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
const int N=2e6+5,base=999983,Mod=998244353;
bool SSS;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){f=(ch=='-'?-f:f);ch=getchar();}
	while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*f;
}
int n,m,k;
struct XXX{
	int u,v,w;
}e[N],q[N];int cnt;
int c[N],a[11][10005];
int fa[N];
int find(int x){
	return (fa[x]==x?x:fa[x]=find(fa[x]));
}
inline bool cmp(XXX a,XXX b){
	return a.w<b.w;
}
bool TTT;
signed main(){
//	printf("%lld Mib\n",(int)(&TTT-&SSS)/1024/1024);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	For(i,1,m){
		int u=read(),v=read(),w=read();
		e[i]={u,v,w};
	}
	For(i,1,k){
		c[i]=read();
		For(j,1,n)a[i][j]=read();
	}For(i,1,n) fa[i]=i;
	sort(e+1,e+m+1,cmp);
	For(i,1,m){
		int u=e[i].u,v=e[i].v;
		if(find(u)==find(v))continue; 
		q[++cnt]=e[i];
		fa[find(v)]=find(u);
	}
	int ans=1e16;
	int p=0;
	For(i,1,n) if(c[i]==0) p++; 
	For(t,0,(1<<k)-1){
		if(p==n&&t!=(1<<k)-1)continue;
		For(i,1,n+k) fa[i]=i;
		int tot=0;
		int sum=0;
		For(i,1,cnt) e[++tot]=q[i]; 
		For(i,1,k)if(t&(1<<(i-1))){
			sum+=c[i];
			For(j,1,n) if(a[i][j]<=q[cnt].w)e[++tot]={i+n,j,a[i][j]}; 
		}if(sum>=ans) continue;
		stable_sort(e+1,e+tot+1,cmp);
		For(i,1,tot){
			int u=e[i].u,v=e[i].v;
			if(find(u)==find(v))continue; 
			fa[find(v)]=find(u);
			sum+=e[i].w;
		}ans=min(ans,sum);
	}
	printf("%lld\n",ans);
	return 0;
}

