#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+10;
int a[N][50],c[50],f[N],n,m,k,ans;
struct edge{
	int u,v,w,uc;
};
vector<edge> el;
bool cmp(edge r1,edge r2){
	return r1.w<r2.w;
}
int find(int x){
	return (x==f[x])?x:f[x]=find(f[x]); 
} 
void kruskal(){
	int cnt=0;
	for(int i=0;i<el.size();i++){
		if(cnt==n-1) break;
		int x=find(el[i].u),y=find(el[i].v);
		if(x==y) continue;
		f[y]=x,cnt++,ans+=el[i].w;
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		edge tmp;
		tmp.u=u,tmp.v=v,tmp.w=w;
		el.push_back(tmp);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++) scanf("%lld",&a[j][i]);
	}
	sort(el.begin(),el.end(),cmp);
	kruskal();
	printf("%lld\n",ans);
	return 0;
}
