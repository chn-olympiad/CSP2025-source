#include<bits/stdc++.h>
using namespace std;
struct o{
	int a,b,c;
}a[2000005];
int n,m,k,h,fa[11000],ci[15],use[15];
long long ans;
bool cmp(o x,o y){
	return x.c<y.c;
}
int f(int x){
	if(fa[x]==x)return x;
	return fa[x]=f(fa[x]);
}
void g(){
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	int nm=0;
	long long s=0;
	for(int i=1;i<=k;i++){
		if(ci[i]){
			nm++;
			s=s+1ll*use[i];
		}
	}
	int u,v,w,l,r,g=0;
	for(int i=1;i<=h;i++){
		u=a[i].a,v=a[i].b,w=a[i].c;
		if((u<=n&&v<=n)||(ci[u-n]==1)){
			l=f(u);
			r=f(v);
			if(l!=r){
				g++;
				fa[r]=l;
				s=s+1ll*w;
			}
			if(g==n+nm-1){
				break;
			}
		}
	}
	ans=min(ans,s);
}
void dfs(int x){
	if(x==k+1){
		g();
		return;
	}
	ci[x]=0;
	dfs(x+1);
	ci[x]=1;
	dfs(x+1);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
	}
	h=m;
	long long qweqwe=1e18;
	for(int i=1;i<=k;i++){
		scanf("%d",&use[i]);
		int sfssf=0;
		for(int j=1;j<=n;j++){
			h++;
			scanf("%d",&a[h].c);
			if(a[h].c!=0)sfssf=1;
			a[h].a=n+i;
			a[h].b=j;
		}
		if(sfssf==0){
			qweqwe=min(qweqwe,1ll*use[i]);
		}
	}
	if(qweqwe!=1e18){
		printf("%lld",qweqwe);
		return 0;
	}
	sort(a+1,a+h+1,cmp);
	ans=1e18;
	dfs(1);
	printf("%lld",ans);
	return 0;
}
