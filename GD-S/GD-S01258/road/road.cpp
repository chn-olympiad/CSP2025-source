#include<bits/stdc++.h>

using namespace std;

#define int long long

int n,m,k;
int c[2000010];
int b[150][15010];
int cnt;
int x,y,z;
int ans=1e18;
int fa[150010];

bool vis[1010];

int findn(int x){
	return fa[x]==x?x:fa[x]=findn(fa[x]);
}

struct edge{
	int x,y,z;
}a[3000010];

bool cmp(edge a,edge b){
	return a.z<b.z;
}

void kruskal(int x){
	int sum=0,tot=0;
	cnt=m;
	
	for(int i=1;i<=k;i++) vis[i]=0;
	
	for(int i=1;i<=n+k;i++) fa[i]=i;
	
	for(int i=1;i<=k;i++){
		if((x>>(i-1))&1){
			tot++;
			//if(x==16) printf("%lld ",i);
			vis[i]=1;
			sum+=c[i];
			for(int j=1;j<=n;j++){
				a[++cnt].x=i+n;
				a[cnt].y=j;
				a[cnt].z=b[i][j];
			}
		}
	}
	
	//if(x==16) puts("");
	
	int oto=0;
	
	sort(a+1,a+1+cnt,cmp);
	
	for(int i=1;i<=cnt;i++){
		if(a[i].x>n&&!(vis[a[i].x-n])) continue;
		int fx=findn(a[i].x),fy=findn(a[i].y);
		if(fx==fy) continue;
		//if(x==16) printf("aasasa %lld %lld %lld\n",a[i].x,a[i].y,a[i].z);
		sum+=a[i].z;
		if(sum>=ans) return;
		oto++;
		fa[fy]=fx;
		if(oto==n+tot-1) break;
	}
	ans=min(ans,sum);
	
	//printf("qwq %lld %lld\n",x,sum);
	//if(sum==5095741225) printf("asaas %lld\n",x);
	
	//if(x==16) printf("666aa %lld\n",sum);
	/*bool fg=0;
	for(int i=2;i<=n+k;i++){
		if(i>n&&(!vis[i])) continue;
		if(findn(i)!=findn(1)){
			fg=1;
			break;
		}
	}
	if(fg) puts("noooo");*/
	
	//if(sum==5182974424) puts("qwq");
	
	//printf("qwq %lld\n",ans);
}

signed main(){
	
	//freopen("road3.in","r",stdin);
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&b[i][j]);
		}
	}
	for(int i=0;i<=(1ll<<k)-1;i++){
		//if(i==16) continue;
		kruskal(i);
	}
	printf("%lld",ans);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
