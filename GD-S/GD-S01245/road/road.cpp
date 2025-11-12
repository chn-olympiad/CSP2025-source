#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
struct items{
	int u,v,w,p;
}edge[N];
int fa[N];
int n,m,k;
int hh[N];
int c[N];
int cnt,ans;
int ecnt;
int rr;
bool cmp(items A,items B){
	return A.w<B.w;
} 
int find(int x){
	if(fa[x]==x)return x;
	else return fa[x]=find(fa[x]);
}
void get(int y){
	cnt=ecnt=0;
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(int i=1;i<=k;i++)if(hh[i])cnt+=c[i];
	if(cnt>=ans)return;
	for(int i=1;i<=rr;i++){
		if(!hh[edge[i].p])continue;
		if(find(edge[i].u)==find(edge[i].v))continue;
		fa[find(edge[i].u)]=find(edge[i].v);
		cnt+=edge[i].w;
		if(cnt>=ans)return;
		ecnt++;
		if(ecnt==n+y-1)break;
	}
	ans=min(ans,cnt);
}
void dfs(int x,int y){
	if(x==k+1){
		get(y);
		return;
	}
	for(int i=0;i<=1;i++){
		hh[x]=i;
		if(i==1)y++;
		dfs(x+1,y);
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	ans=1e18+5; 
	hh[0]=1;
	bool flag=1;
	for(int i=1;i<=m;i++){
		cin>>edge[i].u>>edge[i].v>>edge[i].w;
		edge[i].p=0;
	}
	rr=m;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0)flag=0;
		for(int j=1;j<=n;j++){
			rr++;
			edge[rr].u=i+n;
			edge[rr].v=j;
			edge[rr].p=i;
			cin>>edge[rr].w;
		}
	}
	sort(edge+1,edge+1+rr,cmp);
	if(!flag)dfs(1,0);
	else{
		for(int i=1;i<=k;i++)hh[i]=1;
		get(k);
	}
	cout<<ans<<"\n";
	
	return 0;
}
