#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n,m,k;
struct edge{
	int u,v,w;
}e[10000010];
int fa[1000010];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
bool cmp(edge x,edge y){
	if(x.w>y.w)return 0;
	return 1;
}
int c[10010];
vector<int> vv[1050]; 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=10*n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	if(k==0){
		int ans=0;
		sort(e+1,e+n+1,cmp);
		int cnt=0;
		for(int i=1;i<=m;i++){
			int u=e[i].u,v=e[i].v;
			if(find(u)!=find(v)){
				fa[v]=find(u);
				cnt++;
				ans+=e[i].w;
			}
			if(cnt==n-1)break;
		}
		cout<<ans<<endl;
	}else{
		int cnt=m,ans=0;
		for(int i=1;i<=k;i++){
			cin>>c[i];
			for(int j=1;j<=n;j++){
				cnt++;
				int t;cin>>t;
				e[cnt].u=n+i,e[cnt].v=j,e[cnt].w=t;
			}
		}
		sort(e+1,e+cnt+1,cmp);
		int num=0;
		for(int i=1;i<=cnt;i++){
			int u=e[i].u,v=e[i].v;
			if(find(u)!=find(v)){
				fa[v]=find(u);
				num++;
				ans+=e[i].w;
				vv[u].push_back(v),vv[v].push_back(u);
				vv[u].push_back(e[i].w),vv[v].push_back(e[i].w);
			}
			if(num==n+k-1)break;
		}
		for(int i=n+1;i<=n+k;i++){
			if(vv[i].size()==2){
				ans-=vv[i][1];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
