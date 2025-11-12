#include<bits/stdc++.h>
using namespace std;
const int MAXM=1e6+5;
const int MAXN=1e4+5;
long long n,m,k;
long long ans=LONG_LONG_MAX;
struct node{long long u,v,w;}e[MAXM];
int fa[MAXN];
long long a[15][MAXN];
long long l[1005][1005];
long long jl[1005][1005];
long long sum,s;
inline long long read(){
	char x=getchar();
	s=0;
	while(!('0'<=x&&x<='9'))x=getchar();
	while('0'<=x&&x<='9'){
		s*=10;
		s+=x-'0';
		x=getchar();
	}
	return s;
}
inline bool cmp(node a,node b){return a.w<b.w;}
inline int find(int x){
	if(fa[x]!=x)fa[x]=find(fa[x]);
	return fa[x];
}inline void kruscal(int now,int nowm){
	sum=now;
	int b=0;//±ßÊý 
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(e+1,e+1+nowm,cmp);
	for(int i=1;i<=nowm;i++){
		int ex=find(fa[e[i].u]),ey=find(fa[e[i].v]);
		if(ex==ey)continue;
		fa[ex]=ey;
		b++;
		sum+=e[i].w;
		if(b==n-1){
			ans=min(ans,sum);
			return;
		}
	}
}inline void dfs(int x,int num){
	if(x==k+1)return;
	dfs(x+1,num);
	int tail=0;
	if(num+a[x][0]<=ans){
		num+=a[x][0];
		for(int i=1;i<=n;i++)for(int j=1;j<i;j++)jl[i][j]=l[i][j];
		for(int i=1;i<=n;i++)for(int j=1;j<i;j++)l[i][j]=min(l[i][j],a[x][i]+a[x][j]);
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				if(l[i][j])continue;
				e[++tail].u=i;
				e[tail].v=j;
				e[tail].w=l[i][j];
			}
		}
		kruscal(num,tail);
		dfs(x+1,num);
		for(int i=1;i<=n;i++)for(int j=1;j<i;j++)l[i][j]=jl[i][j];
	}
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)e[i].u=read(),e[i].v=read(),e[i].w=read();
	kruscal(0,m);
	if(k==0){
		printf("%lld",ans);
		return 0;
	}
	for(int i=1;i<=k;i++){
		bool flag=true;
		a[i][0]=read();
		if(a[i][0]!=0)flag=false;
		for(int j=1;j<=n;j++){
			a[i][j]=read();
			if(a[i][j]!=0)flag=false;
		}
		if(flag){
			printf(0);
			return 0;
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)l[i][j]=LONG_LONG_MAX;
	for(int i=1;i<=m;i++)l[min(e[i].u,e[i].v)][max(e[i].u,e[i].v)]=min(l[min(e[i].u,e[i].v)][max(e[i].u,e[i].v)],e[i].w);
	dfs(1,0);
	printf("%lld",ans);
	return 0;
}

