#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,K,c[15],now[15],fa[10015];
priority_queue<pair<int,int> > q;
struct node{
	int u,v,w;
}E[1000005],a[15][10015];
bool cmp(node x,node y){
	return x.w<y.w;
}
int get_fa(int u){
	return fa[u]==u?u:fa[u]=get_fa(fa[u]);
}
ll solve(int s){
	for(int i=1;i<=n+K;i++)fa[i]=i;
	ll ans=0;
	int cnt=n+__builtin_popcount(s)-1;
	while(!q.empty())q.pop();
	for(int i=0;i<=K;i++){
		if(!i||(s&(1<<(i-1)))){
			now[i]=1;
			q.push(make_pair(-a[i][1].w,i));
			ans+=c[i];
		}
	}
	while(cnt){
		int x=q.top().second;
		q.pop();
		int u=a[x][now[x]].u,v=a[x][now[x]].v,w=a[x][now[x]].w;
		now[x]++; 
		if((x==0&&now[x]<=n-1)||(x!=0&&now[x]<=n)){
			q.push(make_pair(-a[x][now[x]].w,x)); 
		}
		if(get_fa(u)!=get_fa(v)){
			fa[fa[u]]=fa[v];
			ans+=w;
			cnt--;
		}
	}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	scanf("%d%d%d",&n,&m,&K);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&E[i].u,&E[i].v,&E[i].w);
	}
	sort(E+1,E+1+m,cmp);
	for(int i=1;i<=K;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			a[i][j].u=n+i,a[i][j].v=j;
			scanf("%d",&a[i][j].w); 
		}
		sort(a[i]+1,a[i]+1+n,cmp);
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	ll ans=0;
	int tot=0;
	for(int i=1;i<=m;i++){
		int u=E[i].u,v=E[i].v;
		if(get_fa(u)!=get_fa(v)){
			fa[fa[u]]=fa[v];
			ans+=E[i].w;
			a[0][++tot]=E[i];
		}
	}
	for(int i=1;i<=(1<<K)-1;i++){
		ans=min(ans,solve(i));
	}
	printf("%lld",ans);
}
