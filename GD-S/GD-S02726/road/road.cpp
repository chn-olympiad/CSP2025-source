#include<bits/stdc++.h>
#define file(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define int long long
using namespace std;
const int N=1e5+530;
const int M=1e7+530;
int n,m,k;
inline int read(){
	int f=1,res=0;
	char c=getchar();
	while(c=='-') f=-f,c=getchar();
	while(c>='0' && c<='9') res=(res<<3)+(res<<1)+c-'0',c=getchar();
	return f*res;
}
struct Edge{
	int from,to,cost;
}edge[M+10*N];
int cnt=0;
int f[M];
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
int get1(int x){
	int res=0;
	while(x){
		res+=x&1;
		x>>=1;
	}
	return res;
}
bool cmp(Edge x,Edge y){
	return x.cost<y.cost;
}
int a[N],c[N];
signed main(){
	file(road);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		int u,v,w;
		edge[++cnt]={u=read(),v=read(),w=read()};
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			edge[++cnt]={n+i,j,a[j]=read()};
		}
	}
	int ans=1e18;
	bool vis[N]={};
	sort(edge+1,edge+1+cnt,cmp);
	for(int st=0;st<=(1<<k)-1;st++){
		int newm=n+get1(st)-1;
		int sum=0;
		for(int i=1;i<=newm+10;i++){
			f[i]=i;
		}
		int cont=0;
		memset(vis,0,sizeof vis);
		for(int i=1;i<=cnt;i++){
			int fx=find(edge[i].to),fy=find(edge[i].from);
			if(fx==fy) {continue;}
			if(edge[i].from>n){
				int xx=edge[i].from-n;
				if(!(st>>(xx)&1)){continue;}
				if(vis[edge[i].from-n]==0){
					sum+=c[edge[i].from-n],vis[edge[i].from-n]=1;
				}
			}
			f[fx]=fy;
			sum+=edge[i].cost;
			cont++;
			if(cont==newm) break;
		}
		if(cont==newm)
		ans=min(ans,sum);
	}
	cout<<ans<<endl;
	return 0;
}//还是比原来多2e7吗，还能蒸吗 
//哈哈哈对啦，666玄学问题，-错了，+对了 wc 
