#include<bits/stdc++.h>
using namespace std;
const int N=1111,M=1e6+5;
int n,m,k,ans,cnt,fa[N];
struct Node{
	int x,y,w,bw;
}edge[N];
bool cmp(Node x,Node y){return x.w<y.w;}
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) cin>>edge[i].x>>edge[i].y>>edge[i].w;
	sort(edge+1,edge+1+m,cmp);
	for(int i=1;i<=m;i++){
		int x=find(edge[i].x),y=find(edge[i].y);
		if(x!=y){
			ans+=edge[i].w;
			fa[x]=y;
		}
	}
	for(int i=1;i<=k;cnt=0,i++){
		int a;
		cin>>a;
		for(int j=1;j<=n;j++){
			int x;
			cin>>x;
			edge[j+m*i].x=n+i;
			edge[j+m*i].y=j;
			edge[j+m*i].w=x;
			edge[j+m*i].bw=a;
		}
		sort(edge+1,edge+m+n*i+1,cmp);
		for(int i=1;i<=n;i++) fa[i]=i;
		for(int j=1;j<=m+n*i;j++){
			int x=find(edge[j].x),y=find(edge[j].y);
			if(x!=y){
				cnt+=edge[j].bw;
				fa[x]=y;
			}
		}
		ans=min(ans,cnt);
	}
	return cout<<ans,0;
}
