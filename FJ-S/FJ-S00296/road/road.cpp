#include<bits/stdc++.h>
using namespace std;
const int o=2e6+5;
int n,m,k,x,sum,vis[o],fa[o],size;
long long ans=1e18,c[o];
struct D{
	int to,id;
	long long w;
}es[2*o];
bool cmp(D l,D r){
	return l.w<r.w;
}
int find_fa(int g){
	if(fa[g]==g) return g;
	else return fa[g]=find_fa(fa[g]);
}
long long f(){
	for(int i=1;i<=n+k;i++)
	fa[i]=i;
	int now=n+size; long long p=0;
	for(int i=1;i<=m+sum;i++){
		int u=es[i].id,v=es[i].to;
		if(!vis[u]&&u>n) continue;
		int s1=find_fa(u),s2=find_fa(v);
		if(s1!=s2){
			now--;
			p+=es[i].w;
			fa[s2]=s1;
		}
		if(now==1) return p;
	}
}
void dfs(int g,long long w){
	if(g==k+1){
		ans=min(f()+w,ans);
		return;
	}
	dfs(g+1,w);
	vis[n+g]=1; size++;
	dfs(g+1,w+c[g]);
	vis[n+g]=0; size--;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	scanf("%d%d%d",&es[i].id,&es[i].to,&es[i].w);
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&x);
			sum++;
			es[m+sum].to=j;
			es[m+sum].id=n+i;
			es[m+sum].w=x;
		}
	}
	sort(es+1,es+m+sum+1,cmp);
	dfs(1,0);
	cout<<ans<<endl;
}
