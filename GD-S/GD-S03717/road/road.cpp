#include<bits/stdc++.h>
using namespace std;
const int M=1.2e6+10;
const int N=1e4+10;

struct node{
	int u,v;
	long long w; 
}a[M];

bool cmp(node x,node y){
	return x.w<y.w;
}
int fa[N],d[N];
int n,m,k;

int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}

long long build(int s){
	long long sum=0;
	for(int i=1;i<=s;i++){
		int u=a[i].u,v=a[i].v;
		long long w=a[i].w;
		int fu=find(u),fv=find(v);
		if(fu==fv){
			continue;
		}
		fa[fv]=fa[fu];
		sum+=w;
	}
	return sum;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	
	for(int i=1;i<=m;i++)scanf("%d%d%lld",&a[i].u,&a[i].v,&a[i].w);
	int sum=m;	
	for(int i=1;i<=k;i++){
		long long h=0;
		scanf("%lld",&h);
		for(int j=1;j<=n;j++){
			long long p;
			scanf("%lld",&p);
			a[++sum]={i+n,j,p};
		}
		//for(int i=sum-n+1;i<=sum;i++)printf("%lld ",a[i].w);
		//printf("\n");
	}
	for(int i=1;i<=n+k;i++)fa[i]=i;
	sort(a+1,a+sum+1,cmp);	
	printf("%lld\n",build(sum));
}
/*
4 4 1
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

5 7 0
1 2 15
2 5 8
2 4 2
4 5 4
1 4 1
3 4 3
1 3 10

*/
