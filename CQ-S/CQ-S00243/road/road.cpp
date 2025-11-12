#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N=1e4,MAX_M=1e6,MAX_K=10;
int n,m,k;
int du[MAX_K+10];
ll s[MAX_K+10],c[MAX_K+10],a[MAX_K+10][MAX_N+10];
struct node{
	int u,v,f;
	ll w;
	bool operator<(const node &next)const{
		return w+(du[f]==0?c[f]:0)>next.w+(du[next.f]==0?c[next.f]:0);
	}
};
priority_queue<node>q;
int fath[MAX_N+MAX_K+10];
int getfath(int x){
	return fath[x]==x?x:fath[x]=getfath(fath[x]); 
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n+k;i++)fath[i]=i;
	for(int i=1;i<=m;i++){
		int u,v;
		ll w;
		scanf("%d%d%lld",&u,&v,&w),q.push({u,v,0,w});
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++)scanf("%lld",&a[i][j]),q.push({i+n,j,i,a[i][j]});
	}
	for(int i=0;q.size()&&i<n+k;q.pop()){
		int fu=getfath(q.top().u),fv=getfath(q.top().v),f=q.top().f;
		ll w=q.top().w+(du[f]==0?c[f]:0);
		if(fu!=fv)fath[fu]=fv,s[f]+=w,du[f]++,i++;
	}
	ll sum=s[0];
	for(int i=1;i<=k;i++)if(du[i]>=2)sum+=s[i];
	printf("%lld",sum);
	return 0;
}
