#include<bits/stdc++.h>
using namespace std;
const int N=2e4,M=3e6,K=12;
int n,m,k,tot=0,fa[N];
int d[K];
long long c[K],ans=0x3f3f3f3f3f3f3f;
struct node{
	int u,v;
	long long edge;
}a[M];
bool cnt(const node&x,const node&y){
	return x.edge<y.edge;
}
int find(int x){
	if(fa[x]==x)
		return fa[x];
	return fa[x]=find(fa[x]);
}
void change(int x,int y){
	fa[find(y)]=find(x);
}
long long P(int num){
	for(int i=1;i<=n+k;i++)
		fa[i]=i;
	int T=0,i=1;
	long long res=0;
	for(int i=1;i<=tot&&T<=num-1;i++){
		int x=a[i].u,y=a[i].v,z=a[i].edge;
		int flag=1;
		if(x>n)
			if(d[x-n]==0)
				flag=0;
		if(find(x)==find(y))
			flag=0;
		if(!flag)
			continue;
		change(x,y);
		res+=z;
		T++;
	}
	return res;
}
long long work(int num){
	int nn=0;
	long long res=0;
	memset(d,0,sizeof(d));
	for(int i=1;i<=k;i++){
		d[i]=num%2,num/=2,nn+=d[i];
		if(d[i])
			res=res+c[i];
	}
	res+=P(n+nn);
	return res;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		tot++;
		scanf("%d %d %lld",&a[tot].u,&a[tot].v,&a[tot].edge);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int y=1;y<=n;y++){
			long long z;
			scanf("%lld",&z);
			a[++tot].u=n+i,a[tot].v=y,a[tot].edge=z;
		}
	}
	sort(a+1,a+tot+1,cnt);
	int kk=(1<<k)-1;
	for(int num=0;num<=kk;num++)
		ans=min(ans,work(num));
	printf("%lld",ans);
	return 0;
}
