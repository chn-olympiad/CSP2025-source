#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
struct edge{
	int u,v,w;
}e[1000005];
edge A[2000005];
edge B[2000005];
int ecnt=0;
edge p[15][10005];
edge P[15][10005];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int f[100005];
int c[15];
int find(int x){
	if(x==f[x]){
		return x;
	}
	return f[x]=find(f[x]);
} 
void init(){
	for(int i=1;i<=n+k;i++){
		f[i]=i;
	}
} 
int Ans=1e18;
void dfs(int x,int Ecnt,int S,int tmp){
	if(x==k+1){
		Ans=min(Ans,S+tmp);
		return;
	}
	int T=S,TTTTTR=Ecnt;
	S=0;
	tmp+=c[x];
	init();
	for(int i=1;i<=Ecnt;i++){
		P[x][i]=B[i]=A[i];
	} 
	for(int i=1;i<=n;i++){//O(nlogn2^k)，maybe能过。 
		B[++Ecnt]=p[x][i];
	}
	sort(B+1,B+Ecnt+1,cmp);
	int m=Ecnt;
	Ecnt=0;
	for(int i=1;i<=m;i++){
		if(find(B[i].u)==find(B[i].v)){
			continue;
		}
		A[++Ecnt]=B[i];
		f[find(B[i].u)]=find(B[i].v);
		S+=B[i].w;
//		cout<<B[i].u<<" "<<B[i].v<<" "<<B[i].w<<"\n";
	}
	if(T+tmp-c[x]>S+tmp){
		dfs(x+1,Ecnt,S,tmp);
	}
	for(int i=1;i<=TTTTTR;i++){
		A[i]=P[x][i];
	}
	dfs(x+1,TTTTTR,T,tmp-c[x]);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	freopen("road.txt","w",stderr);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	sort(e+1,e+m+1,cmp);
	init();
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			p[i][j].u=i+n;
			p[i][j].v=j;
			cin>>p[i][j].w;
		}
	}
	int sum=0;
	for(int i=1;i<=m;i++){
		if(find(e[i].u)==find(e[i].v)){
			continue;
		}
		A[++ecnt]=e[i];
		f[find(e[i].u)]=find(e[i].v);
		sum+=e[i].w;
	}
	dfs(1,ecnt,sum,0);
	cout<<Ans<<"\n";
	return 0;
}
/*
这里是T2. 
注意到k只有10，2^k枚举状态然后再跑kruskal？ 
好像时间有点紧张，我们小算一下。 
首先边数是多少？如果k个村庄全都要改造，那么就会有nk条边，再加上原来的边，一共有nk+m~10^6条边。 
然而，我们还有2^k枚举的时间，乘起来就炸了。 
那咋办？ 
别慌，CSP-S总不可能考网络流吧？ 
我有一个很大胆的想法。如果我们率先跑一次kruskal，然后只保留树边，这样边数就是10^5级别的。 
正确性显然，因为新加入的边不改变原来的边的先后顺序。听着好有道理是不是！ 
但是排序带一个log，还是会TLE。 
改变思路，既然2^k*M*log接受不了，我们就把2^k平推了。 
我们考虑进行k+1次kruskal。 
应该能过。 
[16:21]
*/
