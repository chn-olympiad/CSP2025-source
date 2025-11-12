#include<bits/stdc++.h>
using namespace std;
#define N 10010
#define M 1000010

long long read(){
	long long res=0;char c=getchar();bool flag=0;
	while(c<'0'||c>'9'){
		flag|=(c=='-');
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		res=(res<<1)+(res<<3)+(c^48);
		c=getchar();
	}
	return res * ( flag ? -1 : 1 );
}

struct node{
	int u,v;
	long long w;
} e[N*10+M];
bool cmp(node x,node y){
	return x.w<y.w;
}

int n,m,k,cnt;
int fa[N],sum;
int find(int x){ return x==fa[x] ? x : fa[x]=find(fa[x]); }
long long ans;

void Cecilia(){
	n=read();m=read();k=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read();long long w=read();
		e[++cnt].u=u;
		e[cnt].v=v;
		e[cnt].w=w;
	}
	sum=ans=0;
	for(int i=1;i<=k;i++){
		int u=i+n,c=read();
		sum+=c;
		for(int v=1;v<=n;v++){
			long long w=read();
			e[++cnt].u=u;
			e[cnt].v=v;
			e[cnt].w=w;
		}
	}
	ans=0;
	for(int i=1;i<=n+k;i++) fa[i]=i;
	sort(e+1,e+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		int fx=find(e[i].u),fy=find(e[i].v);
		if(fx!=fy){
			fa[fx]=fy;
			ans+=e[i].w;
		}
	}
	printf("%lld",ans+sum);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	Cecilia();
	return 0;
}

