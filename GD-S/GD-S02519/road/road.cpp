#include<bits/stdc++.h>
#define int long long
#define M 3000005
#define N 200005
#define K 20
using namespace std;
int n,m,k,a[N][K],r[N],ans,c[K],mcnt;
bool b[K];
struct Edge{
	int u,v,w;
}e[M],E[M],et[M];
bool cmp(Edge x,Edge y){
	return x.w<y.w;
}
int find(int x){
	if(r[x]!=x)r[x]=find(r[x]);
	return r[x];
}
bool merge(int x,int y){
	if(find(x)==find(y))return 0;
	r[find(x)]=find(y);
	return 1;
}
void dfs(int x){
	if(x==k+1){
		for(int i=1;i<=n*2;i++)r[i]=i;
		for(int i=1;i<=mcnt;i++)E[i]=et[i];
		int ecnt=mcnt;int sum=0;
		for(int i=1;i<=k;i++){
			if(b[i]){
				sum+=c[i];
				for(int j=1;j<=n;j++){
					E[++ecnt]=(Edge){i+n,j,a[i][j]};
				}
			}
		}
		sort(E+1,E+ecnt+1,cmp);
		for(int i=1;i<=ecnt;i++){
			if(merge(E[i].u,E[i].v)){
				//cout<<E[i].u<<' '<<E[i].v<<"!!!\n";
				sum+=E[i].w;
			}
		}
		/*if(sum<ans){
			cout<<sum<<"\n";
			for(int i=1;i<=k;i++)cout<<b[i]<<' ';
			cout<<"\n";
		}*/
		ans=min(ans,sum);
		return;
	}
	dfs(x+1);
	b[x]=1;
	dfs(x+1);
	b[x]=0;
}
int read(){
	char cc=getchar();int x=0;
	while(cc<'0'||cc>'9')cc=getchar();
	while(cc>='0'&&cc<='9')x=(x<<3)+(x<<1)+(cc^48),cc=getchar();
	return x;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)e[i].u=read(),e[i].v=read(),e[i].w=read();
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++)a[i][j]=read();
	}
	for(int i=1;i<=n;i++)r[i]=i;
	int tcnt=0;
	for(int i=1;i<=m;i++){
		if(merge(e[i].u,e[i].v)){
			ans+=e[i].w;
			et[++mcnt]=e[i];
		}
	}
	/*
	{
		bool flag=1;
		for(int i=1;i<=k;i++){
			if(c[i]){
				flag=1;
				break;
			}
			for(int j=1;j<=n;j++){
				if(a[i][j]){
					flag=1;
					break;
				}
			}
		}
		if(flag){
			printf("0\n");
			return 0;
		}
	}*/
	dfs(1);
	printf("%lld\n",ans);
	return 0;
}

