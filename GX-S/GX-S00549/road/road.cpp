#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
const int K=10;
long long n,m,k,r,ans;
struct edge{
	long long st,fi,w;
}e[N+K*N];
vector<long long> c;
long long f[N+K];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
long long find(long long x){
	if(f[x]==x) return x;
	return find(f[x]);
}
void un(long long a,long long b){
	f[find(a)]=find(b);
}
void kru(){
	for(int i=1;i<=r;i++){
		if(find(e[i].st)!=find(e[i].fi)){
			un(e[i].st,e[i].fi);
			ans+=e[i].w;
		}
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		r++;
		long long u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		e[i].st=u;
		e[i].fi=v;
		e[i].w=w;
	}
	for(int i=1;i<=k;i++){
		long long cj;
		scanf("%lld",&cj);
		c.push_back(cj);
		for(int j=1;j<=n;j++){
			r++;
			long long w;
			scanf("%lld",&w);
			e[r].st=i+n;
			e[r].fi=j;
			e[r].w=w;
		}
	}
	sort(e+1,e+1+r,cmp);
	for(int i=1;i<=r;i++){
		f[i]=i;
	}
	kru();
	return 0;
}
