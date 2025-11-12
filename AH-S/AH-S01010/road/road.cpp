#include<cstdio>
#include<algorithm>
using namespace std;
#define int long long
struct edge{
	int u,v,w;
}ed[2000100],eu[20001000];
int n,m,k,c[15],a[15][1001000],f[10010];
int ans=0x3f3f3f3f3f3f3f3f;
bool A=true;
bool cmp(edge xx,edge yy){
	return xx.w<=yy.w;
}
void init(){
	for(int i=1;i<=n+k;i++) f[i]=i;
}
int fa(int x){
	if(f[x]==x) return x;
	return f[x]=fa(f[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%lld %lld %lld",&ed[i].u,&ed[i].v,&ed[i].w);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		if(c[i]) A=false;
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
		}
	}
	if(A){
		init();
		int len=m,cost=0;
		int c2=n+k;
		for(int j=1;j<=m;j++) eu[j]=ed[j];
		for(int j=1;j<=k;j++){
			for(int ii=1;ii<=n;ii++) eu[++len]={ii,n+j,a[j][ii]};
		}
		sort(eu+1,eu+len+1,cmp);
		int cnt=1;
		for(int j=1;j<=len;j++){
			int uu=eu[j].u,vv=eu[j].v,ww=eu[j].w;
			if(fa(uu)==fa(vv)) continue;
			f[fa(uu)]=fa(vv);
			cnt++;
			cost+=ww;
			if(cnt==c2) break;
		}
		printf("%lld",cost);
		return 0;
	}
	for(int i=0;i<(1<<k);i++){
		bool f1=0;
		init();
		int len=m,cost=0,c2=n;
		for(int j=1;j<=m;j++) eu[j]=ed[j];
		for(int j=1;j<=k;j++){
			if(i&(1<<(j-1))){
				cost+=c[j];
				if(cost>=ans){f1=1;break;}
				c2++;
				for(int ii=1;ii<=n;ii++) eu[++len]={ii,n+j,a[j][ii]};
			}
		}
		if(f1) continue;
		sort(eu+1,eu+len+1,cmp);
		int cnt=1;
		for(int j=1;j<=len;j++){
			int uu=eu[j].u,vv=eu[j].v,ww=eu[j].w;
			if(fa(uu)==fa(vv)) continue;
			f[fa(uu)]=fa(vv);
			cnt++;
			cost+=ww;
			if(cost>=ans) break;
			if(cnt==c2) break;
		}
		ans=min(ans,cost);
	}
	printf("%lld",ans);
	return 0;
}
