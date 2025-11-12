#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1e5;
struct tre{
	int f[N],n,siz[N];
	void memsets(int s){
		n=s;
		for (int i=1;i<=n;++i){
			f[i]=i;siz[i]=1;
		}
	}
	int get(int x){
		if (f[x]==x) return x;
		return f[x]=get(f[x]);
	}
	void modify(int x,int y){
		x=get(x);y=get(y);
		if (x==y) return ;
		if (siz[x]<siz[y]) swap(x,y);
		siz[x]+=siz[y];
		siz[y]=0; 
		f[y]=x;
	}
	bool query(int x,int y){
		return get(x)==get(y); 
	}
}t;
struct rec{
	int s,e;
	long long d;
}z[20*N];
struct pai{
	int u,cnt,p[11];
};
long long a[11][N],c[N];
int n,m,k;
long long ans;
void init(){
	scanf("%d%d%d",&n,&m,&k);
	t.memsets(n+k+1);
	for (int i=1;i<=m;++i){
		scanf("%d%d%lld",&z[i].s,&z[i].e,&z[i].d);
	}
	for (int i=1;i<=k;++i){
		scanf("%lld",&c[i]);
		for (int j=1;j<=n;++j){
			scanf("%lld",&a[i][j]);
		}
	}
}
bool cmp(const rec x,const rec y){
	return x.d<y.d;
}
void work(){
	for (int i=1;i<=k;++i){
		for (int j=1;j<=n;++j){
			z[++m].s=n+i;
			z[m].e=j;
			z[m].d=a[i][j];
		}
		z[++m].s=n+k+1;
		z[m].e=n+i;
		z[m].d=c[i];
	}
	z[++m].s=n+k+1;
	z[m].e=1;
	z[m].d=0;
	sort(z+1,z+1+m,cmp);
	for (int i=1;i<=m;++i){
		if (t.query(z[i].s,z[i].e)) continue;
		t.modify(z[i].s,z[i].e);
		ans+=z[i].d;
	}
	printf("%lld\n",ans);
	ans=0;
}
int tt;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&tt);
	while (tt--){
		init();
		work();
	}
	return 0;
}
