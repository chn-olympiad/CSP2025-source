#include<bits/stdc++.h>
using namespace std;
int n,m,k,f[10050];
long long sum[15],ck[15],ans=1e18;
struct ab{
	int u,v;
	long long a;
}c[15][10050],b[1000050];
int fa(int x){
	if(x==f[x])return x;
	return f[x]=fa(f[x]);
}
bool cmp(ab a,ab b){
	return a.a<b.a;
}
vector<ab>v[15];
void cz(ab t,int N){
	if(fa(t.u)!=fa(t.v))v[N].emplace_back(t),sum[N]+=t.a,f[f[t.v]]=f[t.u];
	return;
}
void dfs(int p,int N,long long now){
	if(p==k+1)return;
	int i=0,j=1,x=v[N-1].size();
	for(int i=1;i<=n+p;++i)f[i]=i;
	sum[N]=now+ck[p];
	while(i<x&&j<=n){
		if(v[N-1][i].a<c[p][j].a)cz(v[N-1][i],N),++i;
		else cz(c[p][j],N),++j;
	}
	while(i<x)cz(v[N-1][i],N),++i;
	while(j<=n)cz(c[p][j],N),++j;
	if(sum[N]<sum[N-1])ans=min(ans,sum[N]),dfs(p+1,N+1,now+ck[p]);
	sum[N]=0,v[N].clear(),dfs(p+1,N,now);
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i)cin>>b[i].u>>b[i].v>>b[i].a,swap(b[i].u,b[i].v);
	for(int i=1;i<=k;++i){
		cin>>ck[i];
		for(int j=1;j<=n;++j)cin>>c[i][j].a,c[i][j].u=j,c[i][j].v=n+i;
		sort(c[i]+1,c[i]+1+n,cmp);
	}
	sort(b+1,b+1+m,cmp);
	for(int i=1;i<=n;++i)f[i]=i;
	for(int i=1;i<=m;++i)cz(b[i],0);
	ans=sum[0],dfs(1,1,0),cout<<ans;
	return 0;
}
