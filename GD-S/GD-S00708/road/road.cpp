#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+7;
int n,m,k;
int fa[N],s[N];
ll ans,tot,y;
int o=1;
struct node{
	int st,to,w,op,q;
};
vector<node> e;
bool cmp(node a,node b){
	return a.w<b.w;
}
int find(int x){
	return x==fa[x]?x:(fa[x]=find(fa[x]));
}
void kruskal(){
	for(int i=0;i<m;i++){
		int x=find(e[i].st);
		int y=find(e[i].to);
		if(x==y)continue;
//		cout<<e[i].w<<" ";
		ans+=e[i].w;
		if(e[i].op&&o){
			o=0;
			ans+=y;
			ans+=e[i].q;
		}
		fa[x]=y;
		tot++;
		if(tot==n-1)break;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1,x,y,w;i<=m;i++){
		scanf("%d%d%d",&x,&y,&w);
		e.push_back({x,y,w,0,0});
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&s[i]);
		for(int j=1,x;j<=n;j++){
			scanf("%d",&x);
			if(i==j)y=x;
			if(j!=i)e.push_back({i,j,x,1,s[i]});
		}
	}
	m=m+k*n;
	sort(e.begin(),e.end(),cmp);
	kruskal();
	cout<<ans;
	return 0;
}
