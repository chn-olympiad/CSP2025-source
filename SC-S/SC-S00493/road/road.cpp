#include<bits/stdc++.h>
using namespace std;
const int N=1e4+15,M=1e6+15,C=1e5+15;
int n,m,k,c[15],vis[N+10],tag[15];
long long sum=1e18,sumc,numc,num;
struct edge{
	int u,v,w;
}q[C+M];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
long long f(){
	int i=0;long long ans=0,cnt=0;
	memset(vis,0,sizeof(vis));
	while(cnt<n+numc-1){
		i++;
		if(q[i].u>n) if(!tag[q[i].u-n]){
			continue;
		}
		if(vis[q[i].u]==1&&vis[q[i].v]==1) continue;
		vis[q[i].u]=1;vis[q[i].v]=1;
		ans+=q[i].w;cnt++;
	}
	return ans;
}
void dfs(int step){
	if(step>k){
		sum=min(sum,sumc+f()); 
		return ;
	}
	tag[step]=1;sumc+=c[step];numc++;dfs(step+1);
	tag[step]=0;sumc-=c[step];numc--;dfs(step+1);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);num=m;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&q[i].u,&q[i].v,&q[i].w);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			q[++num].u=i+n;q[num].v=j;
			scanf("%d",&q[num].w);
		}
	}
	sort(q+1,q+num,cmp);
	
	dfs(1);
	cout<<sum;
	return 0;
}