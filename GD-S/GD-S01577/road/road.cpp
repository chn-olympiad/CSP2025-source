#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<int,PII> PPI;
const int N=1e4+5,M=2e6+5,K=13;

int n,m,k,a[K],g[K][N];
int f[N+K],cnt;
PPI q[M];

int find(int x){
	if(f[x]!=x) f[x]=find(f[x]);
	return f[x];
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int u,v,c;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&c);
		q[i]={c,{u,v}};
	}
	LL ans=0;
	sort(q+1,q+1+m);
	for(int i=1;i<=m;i++){
		u=q[i].second.first,v=q[i].second.second;
		if(find(u)!=find(v)) f[find(u)]=find(v),q[++cnt]=q[i],ans+=q[i].first;
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&a[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&g[i][j]);
			if(g[i][j]<q[n-1].first) q[++cnt]={g[i][j],{i+n,j}};
		}
	}
	sort(q+1,q+1+cnt);
	LL res;
	for(int i=1;i<(1<<k);i++){
		res=0;
		for(int j=1;j<=k;j++){
			if((i>>(j-1))&1) res+=a[j];
		}
		for(int j=1;j<=n+k;j++) f[j]=j;
		for(int j=1;j<=cnt;j++){
			u=q[j].second.first,v=q[j].second.second;
			if(u>n&&((i>>(u-n-1))&1)==0) continue;
			if(find(u)!=find(v)){
				res+=q[j].first;
				f[f[u]]=f[v];
			}
		}
		ans=min(ans,res);
	}
	cout<<ans;
	return 0;
} 
