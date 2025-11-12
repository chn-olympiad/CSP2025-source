#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int> PII;
const int M=1e6+10,N=1e4+10;
struct edge{
	int u,v,w;
	bool operator<(const edge &x){
		return w<x.w;
	}
}e[M];
int f[N];
int find(int x){
	if(x!=f[x])f[x]=find(f[x]);
	return f[x];
}
void merge(int a,int b){
	int fa=find(a),fb=find(b);
	f[fa]=fb;
}
int c_u[20],c_v[20],c_w[20];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int ui,vi,wi;
		scanf("%d%d%d",&ui,&vi,&wi);
		e[i]={ui,vi,wi};
	}
	sort(e+1,e+m+1);
	long long sum=0;
	for(int i=1;i<=n;i++)f[i]=i;
	
	for(int i=1;i<=m;i++){
		if(find(e[i].u)!=find(e[i].v)){
			merge(e[i].u,e[i].v);
			sum+=e[i].w;
		}
	}
	printf("%lld",sum);
	return 0;
}