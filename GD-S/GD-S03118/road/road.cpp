#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ans=1e18;
int n,m,k,tc,td,o[15];
int g[15][10010],f[20010];
struct node{
	int x,y,v,b;
}a[1000010],c[10010],d[100010];//
bool cmp(node x,node y){
	return x.v<y.v;
}
int fd(int x){
	return f[x]==x?x:f[x]=fd(f[x]);
}
node R(node x){
	x.x=o[x.x-n]+n;
	return x;
}
int st(){
	int i=1,j=1,t=0;
	while(o[d[j].x-n]==0&&j<=td)j++;
	while(i<=tc&&j<=td){
		if(c[i].v<d[j].v)a[++t]=c[i],i++;
		else a[++t]=R(d[j]),j++;
		while(o[d[j].x-n]==0&&j<=td)j++;
	}
	while(i<=tc)a[++t]=c[i],i++;
	while(j<=td){
		a[++t]=R(d[j]),j++;
		while(o[d[j].x-n]==0&&j<=td)j++;
	}
	return t;
}
ll Kru(int n,int m){
//	printf("%d %d\n",n,m);//
	ll res=0;
	for(int i=0;i<=n;i++)f[i]=i;
	sort(a+1,a+m+1,cmp);
//	for(int i=1;i<=m;i++)//
//		printf("%d %d %d\n",a[i].x,a[i].y,a[i].v);
	for(int i=1;i<=m;i++)
		if(fd(a[i].x)!=fd(a[i].y))
			f[fd(a[i].x)]=f[fd(a[i].y)],res+=a[i].v,a[i].b=1;
//	printf("%lld\n",res);//
	return res;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].v);
	ans=Kru(n,m);
	for(int i=1;i<=m;i++)
		if(a[i].b)c[++tc]=a[i];
	int mx=0,L=1;
	for(int i=1;i<=k;i++){
		scanf("%d",&g[i][0]);
		mx=max(mx,g[i][0]);
		for(int j=1;j<=n;j++){
			scanf("%d",&g[i][j]);
			d[++td].x=n+i,d[td].y=j,d[td].v=g[i][j]; 
		}
	}
	if(mx==0)L=(1<<k)-1;
	sort(d+1,d+td+1,cmp);
	for(int i=L;i<(1<<k);i++){
		ll res=0;
		int N=0,M=0;
		for(int j=0;j<k;j++){
			if(i&(1<<j))o[j+1]=++N,res+=g[j+1][0];
			else o[j+1]=0;
		}
		M=st();
		res+=Kru(N+n,M);
		ans=min(ans,res);
	}
	printf("%lld\n",ans);
	return 0;
}
//ll int
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
