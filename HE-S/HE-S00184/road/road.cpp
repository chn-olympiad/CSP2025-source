#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool st;//
ll read(){
	ll x=0;short f=1;char s=getchar();
	while(s<48||s>57){f=s=='-'?-1:1;s=getchar();}
	while(s>47&&s<58){x=x*10+(s&15);s=getchar();}
	return x*f;
}
const int N=1e4+15,M=2e6+5;
int n,m,k,fa[N],tot;ll sum;
struct edge{int u,v,w;}e[M];
bool cmp(edge x,edge y){return x.w<y.w;}
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
bool ed;//
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
//	cout<<(&st-&ed)/1048576.0<<'\n';//
	n=read();m=read();k=read();tot=m;
	for(int i=1;i<=n+k;++i)fa[i]=i;
	for(int i=1;i<=m;++i){
		e[i].u=read();
		e[i].v=read();
		e[i].w=read();
	}
	for(int i=1;i<=k;++i){
		sum=sum+read();
		for(int j=1;j<=n;++j){
			e[++tot].u=n+i;
			e[tot].v=j;
			e[tot].w=read();
		}
	}
	m=tot;tot=0;sort(e+1,e+m+1,cmp);
	for(int i=1,u,v;i<=m;++i){
		u=find(e[i].u);v=find(e[i].v);
		if(u==v)continue;++tot;
		sum=sum+e[i].w;fa[v]=u;
		if(tot==n+k-1)break;
	}
	printf("%lld",sum);
	return 0;
}//Usami Sumireko,Violet_Detector
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 1 0 0 4
0 0 3 2 0
*/
//Finally I can solve (maybe) T1 at CSP-S.But it's too late,isn't it?
//...At the same time I can't solve T2 yet.
//k<=10,think how to zip it.
//Or maybe it has other strange solution.
//For 1~4,just use kruskal.
//For 5~16...Oh I don't know how prim worked so I can't type it.Sad.
//For all the 'A's,leave the extra edge which the value equals 0.And then run kruskal.
//12 datas,48 pts...Fine,that's it.
//*sigh
