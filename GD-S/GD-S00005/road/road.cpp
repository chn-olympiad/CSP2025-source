#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+20,M=1e6+20;
struct Edge{
	int a,b;ll w;
	bool operator<(const Edge v){
		if(w!=v.w)return w<v.w;
		return a<v.a;
	}
}E[M],E2[M],E3[M];
ll v2[11][N],c[11];
int p[N];
int find(int x){
	if(x==p[x])return p[x];
	return p[x]=find(p[x]);
}
int n,m,k,idx,ridx;
ll ans,res;
void kruskal0(){
	for(int i=1;i<=n+k;i++)p[i]=i;
	sort(E2+1,E2+1+idx);
	for(int i=1;i<=idx;i++){
		int a=E2[i].a,b=E2[i].b;ll w=E2[i].w;
		int pa=find(a),pb=find(b);
		if(pa==pb)continue;
		p[pa]=pb;
		res+=w;
		E3[++ridx]={a,b,w};
	}
}
void kruskal(){
	for(int i=1;i<=n+k;i++)p[i]=i;
	sort(E2+1,E2+1+idx);
	for(int i=1;i<=idx;i++){
		int a=E2[i].a,b=E2[i].b;ll w=E2[i].w;
		int pa=find(a),pb=find(b);
		if(pa==pb)continue;
		p[pa]=pb;
		res+=w;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int a,b;ll w;
		cin>>a>>b>>w;
		E[i]={a,b,w};
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>v2[i][j];
	}
	ans=1e18;
	for(int j=1;j<=m;j++)E2[++idx]=E[j];
	kruskal0();
	for(int i=0;i<1<<k;i++){
		res=0;idx=0;
		for(int j=1;j<=ridx;j++)E2[++idx]=E3[j];
		for(int j=1;j<=k;j++)
			if((i>>(j-1))&1){
				res+=c[j];
				for(int t=1;t<=n;t++)E2[++idx]={n+j,t,v2[j][t]};
			}
		kruskal();
		ans=min(ans,res);
	}
	cout<<ans;
	return 0;	
}
