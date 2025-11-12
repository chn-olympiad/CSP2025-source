#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+5,M=1e6+1e5+5;
int n,m,k,c[15],d[10][N],ans;
int f[N];
int find(int x){return f[x]==x?x:find(f[x]);}
struct node{
	int u,v,w;
	friend bool operator<(node x,node y){
		return x.w<y.w;
	}
}ed[M];
int kruscal(int m){
	sort(ed,ed+m);
	int cnt=n,ans;
	for(int i=1;i<=n+k;i++)f[i]=i;
	for(int i=0;i<m&&cnt>1;i++){
		int fx=find(ed[i].u),fy=find(ed[i].v);
		if(fx==fy)continue;
		f[fx]=fy;
		ans+=ed[i].w;
		if(ed[i].v<=n)cnt--;
	}
	return ans;
}
int dfs(int x,int e,int f){
	if(x>k)return kruscal(e)+f;
	int s=dfs(x+1,e,f);
	for(int i=1;i<=n;i++)
		ed[i+e-1]={i,x+n,d[x][i]};
	return min(s,dfs(x+1,e+n,f+c[x]));
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0,u,v,w;i<m;i++)
		cin>>u>>v>>w,ed[i]={u,v,w};
	for(int i=1;i<=k;i++){
		cin>>c[i];
		bool flag=c[i]==0;
		for(int j=1;j<=n;j++)
			cin>>d[i][j],flag=flag&&d[i][j]==0;
		if(flag)return cout<<0,0;
	}
	if(!k){
		sort(ed,ed+m);
		int cnt=n;
		for(int i=1;i<=n;i++)f[i]=i;
		for(int i=0;i<m&&cnt>1;i++){
			int fx=find(ed[i].u),fy=find(ed[i].v);
			if(fx==fy)continue;
			f[fx]=fy;
			ans+=ed[i].w;
		}
		return cout<<ans,0;
	}
	cout<<dfs(0,m,0);
	return 0;
}
