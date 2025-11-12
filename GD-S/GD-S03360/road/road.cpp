#include<bits/stdc++.h>
using namespace std;
const int M=3e6+50,N=1e5+50;
#define int long long
int ans,n,m,k,s;
int fa[N];
struct Edge{
	int u,v,w;
}d[M];
bool cmp(Edge aa,Edge bb){
	return aa.w<bb.w;
}
int find(int father){
	if(father!=fa[father])return fa[father]=find(fa[father]);
	else return father;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(int i=1;i<=m;i++)cin>>d[i].u>>d[i].v>>d[i].w;
	for(int i=1;i<=k;i++){
		cin>>s;
		ans+=s; 
		for(int j=1;j<=n;j++){
			m++;
			d[m].u=n+i,d[m].v=j;
			cin>>d[m].w;
		}
	}
	sort(d+1,d+1+m,cmp);
	for(int i=1;i<=m;i++){
		int fu=find(d[i].u),fv=find(d[i].v);
		if(fu==fv)continue;
		fa[fu]=fv;
		ans=ans+d[i].w;
	}
	cout<<ans;
	return 0;
} 
