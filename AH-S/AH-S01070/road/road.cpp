#include<bits/stdc++.h>
using namespace std;

int n,m,k,x,y,z;
int mp[1005][1005];
struct edg{
	int u,v;
	long long w;
}e[1000005];
long long c[15];
struct node{
	long long c;
	int id;
}a[15][10005];
int fa[10005];
int f[15],r[15][10005];

int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

bool cmp(node a,node b){
	return a.c<b.c;
}

bool cmp1(edg a,edg b){
	return a.w<b.w;
}

void calc1(){
	sort(e+1,e+m+1,cmp1);
	for(int i=1;i<=n;++i)
		fa[i]=i;
	int cnt=0;
	long long ans=0;
	for(int i=1;i<=m&&cnt<n-1;++i){
		int f1=find(e[i].u),f2=find(e[i].v);
		if(f1!=f2){
			fa[f1]=f2;
			ans+=1ll*e[i].w;
			++cnt;
		}
	}
	printf("%lld\n",ans);
	return;
}

void calc2(){
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			mp[i][j]=1e9;
	for(int i=1;i<=m;++i){
		if(e[i].u>e[i].v)
			swap(e[i].u,e[i].v);
		if(mp[e[i].u][e[i].v]>e[i].w)
			mp[e[i].u][e[i].v]=e[i].w;
	}
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			for(int l=1;l<=k;++l)
				if(mp[i][j]>a[l][i].c+a[l][j].c)
					mp[i][j]=a[l][i].c+a[l][j].c;
	m=0;
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			e[++m]={(edg){i,j,mp[i][j]}};
	sort(e+1,e+m+1,cmp1);
	for(int i=1;i<=n;++i)
		fa[i]=i;
	int cnt=0;
	long long ans=0;
	for(int i=1;i<=m&&cnt<n-1;++i){
		int f1=find(e[i].u),f2=find(e[i].v);
		if(f1!=f2){
			fa[f1]=f2;
			ans+=1ll*e[i].w;
			++cnt;
		}
	}
	printf("%lld\n",ans);
	return;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;++i)
		scanf("%d%d%lld",&e[i].u,&e[i].v,&e[i].w);
	if(!k) calc1();
	long long res=0;
	for(int i=1;i<=k;++i){
		scanf("%lld",&c[i]);
		res+=c[i];
		for(int j=1;j<=n;++j)
			scanf("%lld",&a[i][j].c);
	}
	if(!res) calc2();
/*	
	sort(e+1,e+m+1,cmp1);
	for(int i=1;i<=n;++i)
		fa[i]=i;
	int cnt=0;
	long long ans=0;
	for(int i=1;i<=m&&cnt<n-1;++i){
		int f1=find(e[i].u),f2=find(e[i].v);
		if(f1!=f2){
			fa[f1]=f2;
			ans+=1ll*e[i].w;
			++cnt;
		}
	}
	printf("%lld\n",ans);
*/
	return 0;
}
