#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+7;
int n,m,k,ans;
int c[N];
struct Node{
	int v,w;
};
vector<Node> edge[N];
int fa[N];
int find(int x){
	if(fa[x]==x) return x;
	else return find(fa[x]);
}
void verge(int x,int y){
	x=find(x),y=find(y);
	fa[x]=y;
}
bool cmp(Node aa,Node bb){
	return aa.w<bb.w;
}
void T(int u){
	int res=0;
	queue<int> q;
	while(!q.empty()){
		if(res==n+1){
			return;
		} 
		int v=q.front();q.pop();
		for(auto ed:edge[u]){
			if(ed.w<v){
				verge(u,v);
				res++,ans+=ed.w;
			}
			
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
//	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int u,w,v;scanf("%d%d%d",&u,&v,&w);ans+=w;
		edge[u].push_back({v,w});
	}
	for(int i=1;i<=k;i++){
		int ai;scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&ai);
			edge[n+i].push_back({j,ai});
		}
	}
	//T(1);
	printf("%d",ans);
	return 0;
}

