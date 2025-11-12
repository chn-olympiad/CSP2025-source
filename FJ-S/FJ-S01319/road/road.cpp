#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
const int N=1e4+5,M=1e6+1e5+5,K=15;
struct node{
	int u,v,w;
}a[M],tot[N];
int f[N];
int fd(int x){
	if(f[x]==x) return x;
	return f[x]=fd(f[x]);
}
int c[K],d[K][N];
bool cmp(node a,node b){
	return a.w<b.w;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n=read(),m=read(),k=read();
	long long ans=LONG_LONG_MAX;
	for(int i=1;i<=m;i++) a[i].u=read(),a[i].v=read(),a[i].w=read();
	sort(a+1,a+m+1,cmp);
	int t=0;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		int fx=fd(a[i].u),fy=fd(a[i].v);
		if(fx==fy) continue;
		f[fx]=fy;
		tot[++t]=a[i];
		if(t==n-1) break;
	}
	int cnt=t;
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++) d[i][j]=read();
	}
	for(register int i=0;i<(1<<k);++i){
		for(register int j=1;j<=t;++j) a[j]=tot[j];
		for(register int j=1;j<=n+k;++j) f[j]=j;
		cnt=t;
		long long res=0;
		int p=0;
		for(register int j=0;j<k;++j) if((i>>j)&1){
			++p;
			int x=j+1;
			res+=c[x];
//			f[n+x]=n+x;
			for(register int l=1;l<=n;++l) a[++cnt].u=n+x,a[cnt].v=l,a[cnt].w=d[x][l];
		}
//		cout<<res<<'\n';
		sort(a+1,a+cnt+1,cmp);
		int fl=0;
		for(register int j=1;j<=cnt;++j){
			int fx=fd(a[j].u),fy=fd(a[j].v);
			if(fx==fy) continue;
			f[fx]=fy;
			res+=a[j].w;
			++fl;
			if(fl==n+p-1) break;
		}
		ans=min(ans,res);
	}
	printf("%lld",ans);
	return 0;
}


