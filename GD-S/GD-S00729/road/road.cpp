//2-road
#include<bits/stdc++.h>
using namespace std;
struct node{
	long long u,v,w;
}b[11005000];
long long c[4505][4505];
long long a[4505];
int f[4505];
long long ans;
bool cmp(node x,node y){
	return x.w<y.w;
}
int fnd(int x){
	if(x==f[x])return x;
	return f[x]=fnd(f[x]);
}
int main(){
	//cout<<(sizeof(c)+sizeof(a)+sizeof(b)+sizeof(f))/1e6;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,cnt=0,ct=0;
	memset(c,0x7f,sizeof(c));
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		long long u,v,w;
		scanf("%lld %lld %lld",&u,&v,&w);
		c[u][v]=c[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		long long w;
		scanf("%lld",&w);
		for(int j=1;j<=n;j++)
			scanf("%lld",&a[j]);
		for(int j=1;j<=n;j++)
			for(int l=1;l<j;l++)
				c[j][l]=c[l][j]=min(a[j]+a[l],c[j][l]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			b[++cnt]={i,j,c[i][j]};
		}
	}
	sort(b+1,b+1+cnt,cmp);
	for(int i=1;i<=n;i++)
		f[i]=i; 
	for(int i=1;i<=cnt;i++){
		int u=b[i].u,v=b[i].v;
		int fx=fnd(u),fy=fnd(v);
		if(fx==fy)continue;
		f[fx]=fy;
		ans+=b[i].w;
		//cout<<u<<" "<<v<<" "<<b[i].w<<endl;
		if(++ct==n-1)
			break;
	}
	printf("%lld",ans);
	return 0;
}
