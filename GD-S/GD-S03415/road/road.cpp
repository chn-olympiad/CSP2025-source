#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=1e6+10,K=15;
int n,m,k,f[N+K],c[K],a[K][N];
array<int,3> E[M],e[N*11];
int find(int x) {
	if(f[x]!=x) f[x]=find(f[x]);
	return f[x];
}
long long Kruskal(int idx,long long s) {
	int t=idx/n;
	for(int i=1;i<=n+k;i++) f[i]=i;
	int i=1,j=1,cnt=0;
	while(i<=m||j<=idx) {
		array<int,3> cur;
		if(i>m) cur=e[j],j++;
		else if(j>idx) cur=E[i],i++;
		else {
			if(E[i][0]<e[j][0]) cur=E[i],i++;
			else cur=e[j],j++;
		}
		int fu=find(cur[1]),fv=find(cur[2]);
		if(fu!=fv) {
			f[fu]=fv,cnt++,s+=cur[0];
			if(cnt==n+t-1) return s;
		}
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) {
		int u,v,w;cin>>u>>v>>w;
		E[i]={w,u,v};
	}
	sort(E+1,E+m+1);
	for(int i=0;i<k;i++) {
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	long long ans=4e18;
	for(int s=0;s<(1<<k);s++) {
		int idx=0;long long sum=0;
		for(int i=0;i<k;i++) {
			if((s>>i)&1) {
				sum+=c[i];
				for(int j=1;j<=n;j++) e[++idx]={a[i][j],i+n+1,j};
			}
		}
		sort(e+1,e+idx+1);
		long long mn=Kruskal(idx,sum);
		if(mn!=-1) ans=min(ans,mn);
	}
	cout<<ans<<"\n";
	return 0;
}
