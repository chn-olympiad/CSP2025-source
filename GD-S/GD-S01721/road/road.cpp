#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
using namespace std;
const int N=1e5+5,M=1e6+1e5+5;
int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+ch-48,ch=getchar();
	return x*f;
}
int n,m,k;
struct edge{int u,v,w,id;}e[M];
bool cmp(edge a,edge b){return a.w<b.w;}
int fa[N],entry[N];
int find(int x){return (fa[x]==x)?x:fa[x]=find(fa[x]);}
int c[N];
ll work(int op){
	ll res=0,cnt=0,nn=0;
	for(int i=1;i<=k;i++)
		if((1<<i-1)&op)res+=c[i],nn++,entry[i]=1;
		 else entry[i]=0;
	for(int i=1;i<=n+k;i++)fa[i]=i;
	
	for(int i=1,x,y,fx,fy;i<=m;i++){
		x=e[i].u;y=e[i].v;
		fx=find(x);fy=find(y);
		if(fx==fy||(x>n&&!entry[x-n]))continue;
		fa[fx]=fy;res+=e[i].w;cnt++;
		if(cnt==n+nn-1)break;
	}//cout<<res<<endl;;
	return res;
}
ll ans=1e18;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=m;i++){
		e[i].u=read();e[i].v=read();e[i].w=read();
		e[i].id=0;
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			e[++m].u=n+i;
			e[m].v=j;
			e[m].w=read();
			e[m].id=i;
		}
	}
	sort(e+1,e+1+m,cmp);
	for(int i=0;i<(1<<k);i++)ans=min(ans,work(i));
	printf("%lld",ans); 
	return 0;
}
