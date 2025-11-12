#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
int n,m,k;
const int MAXN=1e6+5;
const int N=1e4+5;
struct ed{
	int x,y,z;
}a[MAXN],b[12][N];
int fa[MAXN],siz[MAXN];
int fin_(int x){
	if(fa[x]==x)return x;
	return fa[x]=fin_(fa[x]);
}
int c[MAXN];
ll ret=1e18;
void merg(int x,int y){
	x=fin_(x);y=fin_(y);
	if(siz[x]<siz[y]){
		swap(x,y);
	}
	siz[x]+=siz[y];
	fa[y]=x;
}
void calc(int S){
	ll ans=0;
	int p[11],len=0,l[11]={0};
	for(int i=0;i<=k;i++){
		if(S>>i&1){
			p[++len]=i;
			ans+=c[i];
		}
	}
	for(int i=1;i<=len;i++)l[i]=1;
	for(int i=1;i<=n;i++){
		fa[i]=i;siz[i]=1;
	}
	int cnt=0;
	while(true){
		int minp=0,minn=1e9+7;
		for(int i=1;i<=len;i++){
			if(minn>b[p[i]][l[i]].z){
				minn=b[p[i]][l[i]].z;
				minp=i;
			}
		}
		if(fin_(b[p[minp]][l[minp]].x)!=fin_(b[p[minp]][l[minp]].y)){
			cnt++;
			ans+=minn;
			if(cnt==n-1){
				ret=min(ret,ans);
				return ;
			}
			if(ans>ret)return ;
			merg(b[p[minp]][l[minp]].x,b[p[minp]][l[minp]].y);
		}
		l[minp]++;
	}
}
bool cmp(ed x,ed y){
	return x.z<y.z;
}
int v[11][N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
	}
	sort(a+1,a+1+m,cmp);
	int nl=0;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		if(fin_(a[i].x)!=fin_(a[i].y)){
			nl++;
			b[0][nl]=a[i];
			fa[fin_(a[i].x)]=fin_(a[i].y);
		}
	}
	bool fl=true;
	for(int i=1;i<=k;i++){
		int minp=1;
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&v[i][j]);
			if(v[i][j]<v[i][minp]){
				minp=j;
			}
		}
		c[i]+=v[i][minp];
		int nl=0;
		for(int j=1;j<=n;j++){
			if(j!=minp){
				b[i][++nl]=(ed){j,minp,v[i][j]};
			}
		}fl&=(!c[i]);
		sort(b[i]+1,b[i]+n,cmp);
	}
	if(fl){
		calc((1<<(k+1))-1);
		printf("%lld\n",ret);
		return 0;
	}
	for(int i=1;i<(1<<(k+1));i+=2){
		calc(i);
	}printf("%lld\n",ret);
}
