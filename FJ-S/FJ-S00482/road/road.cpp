#include<bits/stdc++.h> 
using namespace std;
int rd(){
	int n=0; char c;
	while (!isdigit(c=getchar())) ; n=c-'0';
	while (isdigit(c=getchar())) n=n*10+c-'0';
	return n;
}

int n,m,k;
int c[15], w[15][10004];
struct Edge{
	int u,v,w,S;
	friend bool operator<(const Edge &a,const Edge &b){
		return a.w<b.w;
	}
}Ed[2000006]; int T1;

int fa[15004];
int find(const int &x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

long long Calc(int n,int m,bool flag,int S){
//	printf("Calc: n,m=%d,%d>\n",n,m);
	long long res=0;
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=m;i++){
		if ((Ed[i].S&S)!=Ed[i].S) continue;
		int u=Ed[i].u, v=Ed[i].v;
		if (find(u)!=find(v)){
			res+=Ed[i].w; fa[find(u)]=find(v);
			if (flag) Ed[++T1]=Ed[i];
		}
	}
	return res;
}

void Solve(){
	n=rd(); m=rd(); k=rd();
	for (int i=1;i<=m;i++){
		int u,v,w; u=rd(); v=rd(); w=rd();
		Ed[i]={u,v,w,0};
	}sort(Ed+1,Ed+m+1);
	long long ans=Calc(n,m,1,0); m=n-1;
	for (int i=1;i<=k;i++){
		c[i]=rd();
		for (int j=1;j<=n;j++) Ed[++m]={n+i,j,rd(),1<<i-1};
	}sort(Ed+1,Ed+m+1);
	for (int S=1;S<(1<<k);S++){
		long long sc=0;
		for (int i=1;i<=k;i++) if (S&(1<<i-1)) sc+=c[i];
		ans=min(ans,sc+Calc(n+k,m,0,S));
	}
	printf("%lld\n",ans);
	return ;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int t; t=1;
	while (t--) Solve();
	return 0;
}
