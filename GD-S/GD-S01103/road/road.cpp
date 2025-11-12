#include<bits/stdc++.h>
#define ll long long
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define rf(i,a,b) for(int i=a;i>=b;i--)
char Begin;
int read(){
	int num=0;
	char ch;ch=getchar();
	while(ch<48||ch>57)ch=getchar();
	while(ch>47&&ch<58){
		num=(num<<1)+(num<<3)+(ch^48);
		ch=getchar();
	}return num;
}
ll min(ll x,ll y){return x<y?x:y;}
ll max(ll x,ll y){return x>y?x:y;}
const int N=1e4+15;
const int M=1e6+15;
struct edge{int x,y,d;}E[M];
edge e[15][N],a[1030][N];
bool operator<(edge x,edge y){return x.d<y.d;}
int n,m,K,cnt,fa[N],w[1030];
int find(int x){return fa[x]=(fa[x]==x?x:find(fa[x]));}
int A[15],d[15],now[15],sz[1030];
ll ans,s[1030];
char End;
int main(){
	// std::cerr<<(&End-&Begin)/1024/1024<<std::endl;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	fr(i,1,1023)if(i%2==0)w[i]=w[i/2]+1;
	n=read(),m=read(),K=read();
	fr(i,1,m){
		int p=read(),q=read();
		E[i].x=p,E[i].y=q;
		E[i].d=read();
	}
	fr(i,1,n)fa[i]=i;
	std::stable_sort(E+1,E+1+m);
	cnt=0;
	fr(i,1,m){
		int u=find(E[i].x);
		int v=find(E[i].y);
		if(u==v)continue;
		fa[u]=v,ans+=E[i].d;
		a[0][++cnt]=E[i];
	}
	fr(i,0,K-1){
		A[i]=read();
		fr(j,1,n)e[i][j]={j,i+n+1,read()};
		std::stable_sort(e[i]+1,e[i]+1+n);
	}
	sz[0]=n-1;
	fr(i,1,(1<<K)-1){
		int j=i-(1<<w[i]);
		s[i]=s[j]+A[w[i]];
		ll sum=s[i];m=0;
		fr(k,1,n+K)fa[k]=k;
		for(int k=1,h=1;k<=sz[j]||h<=n;){
			int id=2e9;
			if(k<=sz[j]&&a[j][k].d<id)id=a[j][k].d;
			if(h<=n&&e[w[i]][h].d<id)id=e[w[i]][h].d;
			if(k<=sz[j]&&a[j][k].d==id){
				int u=find(a[j][k].x);
				int v=find(a[j][k].y);
				k++;if(u==v)continue;
				sum+=id,fa[u]=v;
				a[i][++m]=a[j][k-1];
			}else{
				int u=find(e[w[i]][h].x);
				int v=find(e[w[i]][h].y);
				h++;if(u==v)continue;
				sum+=id,fa[u]=v;
				a[i][++m]=e[w[i]][h-1];
			}
		}sz[i]=m;
		if(ans>sum)ans=sum;
	}
	printf("%lld",ans);
}