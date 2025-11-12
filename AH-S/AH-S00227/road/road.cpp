#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long
#define M 1000005
#define N 10005
inline int read(){
	int a=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=a*10+c-'0';
		c=getchar();
	}
	return f*a;
}
struct node{
	int u,v,w,id;
}a[M],e[100000+N];
int n,m,t,f[N+20],c[15],ww[15][N];
bool vis[15];
bool cmp(node a,node b){
	return a.w<b.w;
}
int find(int x){
	if(f[x]==x)return f[x];
	return f[x]=find(f[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),t=read();
	for(int i=1;i<=m;i++)
		a[i].u=read(),a[i].v=read(),a[i].w=read();
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=n;i++)f[i]=i;
	int cnt=0;
	for(int i=1;i<=m;i++){
		int u=a[i].u,v=a[i].v;
		int x=find(u),y=find(v);
		if(x==y)continue;
		f[y]=x,e[++cnt]=a[i];
		if(cnt==n-1)break;
	}
	for(int i=1;i<=t;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			e[++cnt].u=i+n,e[cnt].v=j,e[cnt].id=i;
			e[cnt].w=read();
		}
	}
	sort(e+1,e+1+cnt,cmp);
	ll ans=1e18;
	vis[0]=1;
	for(int i=0;i<=(1<<t)-1;i++){
		ll s=0;
		int tot=0,k=0;
		for(int j=1;j<=t;j++){
			if(i&(1<<(j-1)))vis[j]=1,s+=c[j],k++;
			else vis[j]=0;
			f[n+j]=n+j;
		}
		for(int j=1;j<=n;j++)f[j]=j;
		for(int j=1;j<=cnt;j++){
			if(vis[e[j].id]==0)continue;
			int u=e[j].u,v=e[j].v;
			int x=find(u),y=find(v);
			if(x==y)continue;
			f[y]=x,tot++,s+=e[j].w;
			if(tot==k+n-1)break;
		}
		ans=min(ans,s);
	}
	printf("%lld\n",ans);
	return 0;
}
//4:10
