#include<bits/stdc++.h>
using namespace std;
struct node{
	int u,v,w;
}a[10][10045],E2[20105],E[100025],vis[1034][10015];
int n,m,k,c[10005];
bool cmp(node x,node y){
	return x.w<y.w;
}
int fa[10025],cnt[1300];
int find(int u){
	if(fa[u]==u)return u;
	return fa[u]=find(fa[u]);
}
int lowbit(int u){
	return u&(-u);
}
int merge(int u,int v){
	int i=1,j=1,ncnt=0;
	while(i<=cnt[u]&&j<=n){
		if(vis[u][i].w<a[v][j].w)E2[++ncnt]=vis[u][i++];
		else E2[++ncnt]=a[v][j++];
	}
	while(i<=cnt[u])E2[++ncnt]=vis[u][i++];
	while(j<=n)E2[++ncnt]=a[v][j++];
	return ncnt;
}
long long solve(int id){
//	cout<<"solve"<<id<<"\n";
	int nid=(id^lowbit(id)),last=log2(lowbit(id));
	int ncnt=merge(nid,last);
	long long val=0;
	for(int i=0;i<k;i++)if((id>>i)&1)val+=c[i];
	for(int i=1;i<=ncnt;i++){
		int u=E2[i].u,v=E2[i].v;
		
		u=find(u);v=find(v);
		if(u==v)continue;
//		cout<<E2[i]u<<" "<<v<<"\n";
		vis[id][++cnt[id]]=E2[i];
		fa[u]=v;
		val+=E2[i].w;
	}
	return val;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		E[i]={u,v,w};
	}
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int x;
			cin>>x;
			a[i][j]={n+i+1,j,x};
		}
		sort(a[i]+1,a[i]+n+1,cmp);
	}
	sort(E+1,E+m+1,cmp);
	long long ans=0x3f3f3f3f3f3f3f3fll;
//	for(int i=1;i<=k;i++)
	for(int i=0;i<(1<<k);i++){
		for(int j=1;j<=n+k;j++)fa[j]=j;
		if(i==0){
			long long sum=0;
			for(int j=1;j<=m;j++){
				int u=E[j].u,v=E[j].v;
				u=find(u);v=find(v);
				if(u==v)continue;
				sum+=E[j].w;
				fa[u]=v;
				vis[0][++cnt[0]]=E[j];
			}
			ans=sum;
		}else {
			long long res=solve(i);
//			cout<<i<<" "<<res<<"\n";
			ans=min(ans,res);
		}
	}
	cout<<ans<<"\n";
}
