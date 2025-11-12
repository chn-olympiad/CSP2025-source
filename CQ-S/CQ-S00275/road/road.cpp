#include<bits/stdc++.h>
using namespace std;
#define int long long
#define re register
#define il inline
#define pii pair<int,int>
#define x first
#define y second
#define rd read()
#define gc getchar()
#define debug() puts("-----------")

namespace yzqwq{
	il int read(){
		int x=0,f=1;char ch=gc;
		while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=gc;}
		while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48),ch=gc;
		return x*f;
	}
	il int qmi(int a,int b,int p){
		int res=1;
		while(b){
			if(b&1) res=res*a%p;
			a=a*a%p,b>>=1;
		}
		return res;
	}
	il int gcd(int a,int b){
		if(!b) return a;
		return gcd(b,a%b);
	}
	il void exgcd(int a,int b,int &x,int &y){
		if(!b) return x=1,y=0,void(0);
		exgcd(b,a%b,y,x);
		y-=a/b*x;
		return ;
	}
	mt19937 rnd(time(0));
}
using namespace yzqwq;

const int N=2e6+10,inf=1e18,K=2e4+10;
int n,m,k;
struct node{
	int u,v,w;
}e[N];
int M,res=inf;
int spd[12];
int c[12][K];
bool vis[K];
int f[K];

il int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
il void work(int Spd){
	if(Spd>=res) return ;
	for(re int i=1;i<=n+k;++i) f[i]=i;
	int ans=Spd;
	for(re int i=1;i<=M;++i)
	if(vis[e[i].u]&&vis[e[i].v]){
		if(find(e[i].u)!=find(e[i].v)){
			ans+=e[i].w;
			if(ans>=res) return ; 
			f[find(e[i].u)]=find(e[i].v);
		}
	}
	res=min(res,ans);
	return ;
}

il void solve(){
	n=rd,m=rd,k=rd;
	for(re int i=1;i<=m;++i) e[i]={rd,rd,rd};M=m;
	for(re int i=1;i<=k;++i){
		spd[i]=rd;
		for(re int j=1;j<=n;++j) c[i][j]=rd,e[++M]={i+n,j,c[i][j]};
	}
	sort(e+1,e+M+1,[](node x,node y){
		return x.w<y.w;
	});
	for(re int i=1;i<=n;++i) vis[i]=1;
	for(re int s=0;s<(1ll<<k);++s){
		int Spd=0,ww=0;
		for(re int i=1;i<=k;++i)
		if((s>>(i-1))&1){
			Spd+=spd[i];
			vis[i+n]=1;
		}
		else vis[i+n]=0;
		work(Spd);
	} printf("%lld\n",res);
	return ;
}

signed main(){
//	system("fc road4.ans 111.out");
//	return 0;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int t=1;while(t--)
	solve();
	return 0;
}


