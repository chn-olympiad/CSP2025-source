#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+66;
int n,m,k,fa[N],ans=INT_MAX,c[N];
struct node{
	int u,v,w;
}G[N];
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int Kru(){
	int sum=0;
	sort(G+1,G+1+m,cmp);
	for(int i=1;i<=m;i++){
		int fx=find(G[i].u);
		int fy=find(G[i].v);
		if(fx==fy)continue;
		fa[fx]=fy;
		sum+=G[i].w;
	}
	return sum;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		cin>>G[i].u>>G[i].v>>G[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int a;cin>>a;
			if(c[i]==0&&a==0){
				int fx=find(i);
				int fy=find(j);
				if(fx==fy)continue;
				fa[fx]=fy;
			}
		}
	}
	ans=min(ans,Kru());
	cout<<ans;
	return 0;
}
