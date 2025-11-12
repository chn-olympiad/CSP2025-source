#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
const int M=1e6+5;
long long n,m,k;
long long fa[M],fa1[M];
long long c[15];
long long a[15][N];
long long ans,ans1;
struct edge{
	int u,v;
	long long w;
}e[M];
struct edge_{
	int u,v;
	long long w;
}e1[M];
int cnt=0,cnt1=0;
bool cmp(edge a,edge b){
	return a.w<b.w;
}
bool cmp1(edge_ a,edge_ b){
	return a.w<b.w;
}
void addedge(int u1,int v1,int w1){
	cnt++;
	e[cnt].u=u1;
	e[cnt].v=v1;
	e[cnt].w=w1;
	
	e1[cnt].u=u1;
	e1[cnt].v=v1;
	e1[cnt].w=w1;
}

int bcjc(int x){//查找 
	return fa[x]==x? x: fa[x]=bcjc(fa[x]);
}
void bcjb(int u,int v){//合并 
	long long x=bcjc(u),y=bcjc(v);
	fa[x]=y;
}
void kru(){
	for(int i=1;i<=m;i++){
		int u1=e[i].u,v1=e[i].v;//两个点 
		if(bcjc(u1)!=bcjc(v1)){
			bcjb(u1,v1);
			ans+=e[i].w;
		}
	}
}

int bcjc1(int x){//查找 
	return fa1[x]==x? x: fa1[x]=bcjc(fa1[x]);
}
void bcjb1(int u,int v){//合并 
	long long x=bcjc(u),y=bcjc(v);
	fa1[x]=y;
}
void kru2(){
	for(int i=1;i<=m;i++){
		int u1=e1[i].u,v1=e1[i].v;//两个点 
		if(bcjc1(u1)!=bcjc1(v1)){
			bcjb1(u1,v1);
			ans1+=e1[i].w;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	for(int i=1;i<=M;i++){//并查集初始化 
		fa[i]=i;
		fa1[i]=i;
	}
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		addedge(u,v,w);
		addedge(v,u,w);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	sort(e+1,e+1+m,cmp);
	kru();
	for(int i=1;i<=m;i++){
		int u1=e1[i].u,v1=e1[i].v;
		if(a[u1][v1])e1[i].w+=a[u1][v1];
		if(c[u1])e1[i].w+=c[u1];
		if(c[v1])e1[i].w+=c[v1];
	}
	sort(e1+1,e1+1+m,cmp1);
	kru2();
	cout<<min(ans,ans1);
	/*4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4*/
	return 0;
}
