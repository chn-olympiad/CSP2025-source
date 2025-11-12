#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-48;ch=getchar();}
	return x*f;
}
void write(int x){
	if(x<0){putchar('-');x=-x;}
	if(x>9){write(x/10);}
	putchar((x%10)+48);
}
//15:06 - reading T2.
//15:10 - back to T1
//15:19 - back to T2
//15:20 - have an idea:
//        k<=10,so wecan try to dfs all posible situation.it is O(2^k)
//        at first(k=0),we need to find the minimum spanning tree.it is O(mlogm)
//        then ,remember the n-1 edge,and add new edges from a posible situation.
//        and find tree again.
//        so the time is O((nk)log(nk)*2^k+mlogm)
//15:30 - i do not know whether it is true.just try to finish it.
//15:31 - coding.
//16:11 - damn it.
//16:35 - finished but wrong on test3 qwq
//16:35 - why just O(m) need to take 2.016s?
//16:38 - wdf 
//16:46 - wdf WHY IT IS WRONG.
//17:03 - very red.take a break.
//17:07 - holy shit.I finally find the mistake.I wrongly write a[N][11].
//17:08 - all big sample have been passed.but the longest time is 6.1s.but I can not find why.
//17:09 - I save the code.I HAVE romoved the // in front of the freopen.I hate coding a shit.
//17:10 - back to T1.hope T2 can get more marks.Please.
const int M=1e6+7;
const int N=1e4+7;
struct edge{
	int u,v,w;
}e[M],enew[M],ecopy[M<<2];
int n,m,k,a[11][N],c[11];
int fa[N],ans,tot;

bool cmp(edge x,edge y) {if(x.w<y.w)return true;return false;}
void init_fa() {for(int i=1;i<=n+k;i++)fa[i]=i;}
int find(int x) {if(fa[x]==x)return x;fa[x]=find(fa[x]);return fa[x];}
int renew_village(int x) {int res=0;for(int i=0;i<k;i++){if((x>>i)&1)res+=c[i+1];}return res;}
//==============================================================================
inline void inputed(){
	n=read();m=read();k=read();
	for(int i=1;i<=m;i++){
		int u,v,w;
		e[i].u=read();e[i].v=read();e[i].w=read();
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			a[i][j]=read();
		}
	}
}
//===============================================================================
int mst1(int limit_m,int limit_n){
	sort(e+1,e+1+limit_m,cmp);
	init_fa();
	int res=0;
	for(int i=1;i<=limit_m&&tot<limit_n-1;i++){
		int u=e[i].u,v=e[i].v;
		if(find(u)!=find(v)){
			res+=e[i].w;
			fa[find(u)]=find(v);
			++tot;
			enew[tot].u=u;
			enew[tot].v=v;
			enew[tot].w=e[i].w;
		}
	}
	return res;
}
//===============================================================================
int mst2(int limit_m,int limit_n){
	sort(ecopy+1,ecopy+1+limit_m,cmp);
	init_fa();
	int res=0,tt=0;
	for(int i=1;i<=limit_m&&tt<limit_n-1;i++){
		int u=ecopy[i].u,v=ecopy[i].v;
		if(find(u)!=find(v)){
			res+=ecopy[i].w;
			fa[find(u)]=find(v);
			++tt;
		}
	}
	return res;
}


pair<int,int> get_edge(int x){
	int limit_m=tot,limit_n=n;
	for(int i=1;i<=tot;i++){
		ecopy[i].u=enew[i].u;
		ecopy[i].v=enew[i].v;
		ecopy[i].w=enew[i].w;
	}
	for(int i=0;i<k;i++){
		if((x>>i)&1){
			++limit_n;
			for(int j=1;j<=n;j++){
				ecopy[++limit_m].u=j;
				ecopy[limit_m].v=n+i+1;
				ecopy[limit_m].w=a[i+1][j];
			}
		}
	}
	pair<int,int>tmp;
	tmp.first=limit_m;
	tmp.second=limit_n;
	return tmp;
}
void try_k(){
	for(int i=1;i<(1<<k);i++){
		pair<int,int> tmp=get_edge(i);
		int res=mst2(tmp.first,tmp.second)+renew_village(i);
		ans=min(res,ans);
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	inputed();
	ans=mst1(m,n);
	try_k();
	write(ans);
	return 0;
}
/*
Eng:I want to get a business,please.
Chi:wo xiang  na ge  sheng_yi,xie xie.
/*
5 6 0
1 4 1
1 3 5
4 3 2
4 5 3
5 3 2
3 2 3
--8
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
--13
//505585650
//504898585
//5182974424

*/
