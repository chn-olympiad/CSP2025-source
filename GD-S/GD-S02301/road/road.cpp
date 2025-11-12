#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6+5;
struct node{
	int num,pos;
};
struct edge{
	int u,v,w;
	bool operator < (const edge p){
		return w<p.w;
	}
}e1[11][maxn/10],e2[maxn];
int n,m,k,fa[maxn],ans,cnt,now[maxn],c[maxn];
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
bool cho[maxn];
int getmin(){
	node res={100000000000000000,0};
	for(int i=0;i<=k;i++){
//		cout<<"i:"<<i<<" cho[i]:"<<cho[i]<<" now[i]:"<<now[i]<<"\n";
		if(now[i]>n||(i==0&&now[i]==n))continue;
//		cout<<i<<"\n";
		if(cho[i]){
//			cout<<"res:"<<res.pos<<" "<<res.num<<"\n";
//			cout<<"i:"<<i<<" now[i]:"<<now[i]<<" e1[i][now[i]].w:"<<e1[i][now[i]].w<<"\n";
			if(e1[i][now[i]].w<res.num){
//				cout<<"  &&\n";
				res.num=e1[i][now[i]].w;
				res.pos=i;
//				cout<<" ??res:"<<res.pos<<" "<<res.num<<"\n";
			}
		}
	}
	return res.pos;
}
void solve(){
	int tot=1,pot=n,nans=0;
	for(int i=1;i<=k;i++)if(cho[i])pot++,nans+=c[i];
	for(int i=0;i<=n+k;i++)fa[i]=i,now[i]=1;
	while(tot<pot){
		int tmp=getmin();
//		cout<<"tmp:"<<tmp<<" tot:"<<tot<<" pot:"<<pot<<" nans:"<<nans<<"\n";
//		cout<<"e1[tmp][now[tmp]].u:"<<e1[tmp][now[tmp]].u<<" e1[tmp][now[tmp]].v:"<<e1[tmp][now[tmp]].v<<"\n";
		if(find(e1[tmp][now[tmp]].u)==find(e1[tmp][now[tmp]].v)){
			now[tmp]++;
			continue;
		}
		nans+=e1[tmp][now[tmp]].w;
		fa[find(e1[tmp][now[tmp]].u)]=find(e1[tmp][now[tmp]].v);
		tot++;
		now[tmp]++;
		if(nans>ans)return ;
	}
	ans=nans;
} 
void dfs(int x){
	if(x==k+1){
//		for(int i=1;i<=k;i++)cout<<cho[i]<<" ";
//		cout<<"\n";
		solve();
//		cout<<ans<<"\n";
		return ;
	}
	dfs(x+1);
	cho[x]=1;
	dfs(x+1);
	cho[x]=0;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)cin>>e2[i].u>>e2[i].v>>e2[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int x;
			cin>>x;
			e1[i][j]={i+n,j,x};
		}
		sort(e1[i]+1,e1[i]+n+1);
	}
	sort(e2+1,e2+m+1);
	for(int i=1;i<=m;i++){
		if(find(e2[i].u)==find(e2[i].v))continue;
		e1[0][++cnt]=e2[i];
		ans+=e2[i].w;
		fa[find(e2[i].u)]=find(e2[i].v);
	}
//	for(int i=0;i<=k;i++)for(int j=1;j<=n;j++)cout<<i<<" "<<j<<" "<<e1[i][j].u<<" "<<e1[i][j].v<<" "<<e1[i][j].w<<"\n";
	cho[0]=1;
	dfs(1);
	cout<<ans<<"\n";
	return 0;
}

