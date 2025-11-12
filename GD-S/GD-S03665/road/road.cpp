#include<bits/stdc++.h>

using namespace std;

const long long inf=1000000000000000000;

int n,m,k;
long long ans;
int fa[100007];
int c[17][10007];
struct edge{
	int u,v,w;
}a[2000007];
edge b[2000007];

bool cmp(edge x,edge y){
	return x.w<y.w;
}

int find(int x){
	if(fa[x]!=x) return fa[x]=find(fa[x]);
	else return fa[x];
}

long long solve(int l,int r){
	if(r<l-1) return inf;
	
	long long sum=0;
	int cnt=0;
	for(int i=1;i<=r;i++) b[i].u=a[i].u,b[i].v=a[i].v,b[i].w=a[i].w;
	sort(b+1,b+1+r,cmp);
	for(int i=1;i<=l;i++) fa[i]=i;
	
	for(int i=1;i<=r;i++){
		int u=find(b[i].u),v=find(b[i].v),w=b[i].w;
		if(u!=v){
			fa[u]=fa[v];
			cnt++;
			sum+=w;
			
			if(cnt==l-1) return sum;
		}
	}
	
	return inf;
}

void dfs(int e,int l,int r,int base){
	if(e>k||base>=ans) return;
	
	long long sum=base+c[e][0];
	l++;
	for(int i=1;i<=n;i++){
		r++;
		a[r].u=l,a[r].v=i,a[r].w=c[e][i];
	}
	long long ls=solve(l,r);
	if(ls!=inf) sum+=ls;
	
	if(ls!=inf&&sum<ans) ans=sum;
	if(ls==inf) dfs(e+1,l,r,sum);
	
	l-=1,r-=n;
	dfs(e+1,l,r,base);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d %d %d",&a[i].u,&a[i].v,&a[i].w);
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			scanf("%d",&c[i][j]);
		}
	}
	
	ans=solve(n,m);
	dfs(1,n,m,0);
	
	printf("%lld",ans);
	
	return 0;
} 
