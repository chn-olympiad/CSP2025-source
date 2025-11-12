#include<set>
#include<map>
#include<cmath>
#include<ctime>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<string>
#include<bitset>
#include<cstring>
#include<numeric>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1e4+15;
const int MAXE=1.1e5+15;
const int MAXM=1e6+15;
const int INF=0x3f3f3f3f;
const long long LINF=0x3f3f3f3f3f3f3f3f;
const int IN=4e7+10;
char in[IN];
char*pc=in;
inline int read(){
	int num=0;
	while(*pc<0x30)
	{
		pc++;
	}
	while(*pc>=0x30)
	{
		num=num*10+(*pc++^0x30);
	}
	return num;
}
int n,m,k,c=0;
long long ans=LINF;
struct edge{
	int u,v,w,id;
};
inline bool operator <(edge x,edge y){
	return x.w<y.w;
}
edge a[MAXE],e[MAXM];
int cst[15];
int pre[MAXN];
inline int find(int x){
	while(x^pre[x])
	{
		x=pre[x]=pre[pre[x]];
	}
	return x;
}
inline void kruscal(){
	sort(e+1,e+1+m);
	iota(pre+1,pre+1+n,1);
	for(int i=1;i<=m;i++)
	{
		int x=find(e[i].u),y=find(e[i].v),w=e[i].w;
		if(x^y){
			pre[y]=x;
			c++;
			a[c]=e[i];
		}
	}
}
inline void cal(int s){
	s=s<<1|1;
	long long res=0;
	for(int i=1;i<=k;i++)
	{
		if(s&1<<i){
			res+=cst[i];
		}
	}
	iota(pre+1,pre+1+n+k,1);
	for(int i=1;i<=c;i++)
	{
		if(s&1<<a[i].id){
			int x=find(a[i].u),y=find(a[i].v),w=a[i].w;
			if(x^y){
				res+=w;
				pre[y]=x;
			}
		}
	}
	ans=min(ans,res);
}
inline void solve(){
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=m;i++)
	{
		e[i].u=read();
		e[i].v=read();
		e[i].w=read();
		e[i].id=0;
	}
	kruscal();
	for(int i=1;i<=k;i++)
	{
		cst[i]=read();
		for(int j=1;j<=n;j++)
		{
			c++;
			a[c].u=n+i;
			a[c].v=j;
			a[c].w=read();
			a[c].id=i;
		}
	}
	sort(a+1,a+1+c);
	for(int s=0;s<(1<<k);s++)
	{
		cal(s);
	}
	printf("%lld\n",ans);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	#ifdef LOCAL
	atexit([](){fprintf(stderr,"%.3lfs\n",(double)clock()/CLOCKS_PER_SEC);});
	#endif
	fread(in,1,IN,stdin);
	solve();
	return 0;
}