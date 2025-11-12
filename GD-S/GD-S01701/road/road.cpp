#include<bits/stdc++.h>
#define int long long
using namespace std;
struct edge{
	int x,y,w;
}a[2000005];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int n,m,top,ans,k;
int fa[10005];
int find(int x){
	return fa[x]==x?x:(fa[x]=find(fa[x]));
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,w;
		cin>>x>>y>>w;
		a[++top]={x,y,w};
	}
	for(int i=1;i<=k;i++){
		int j;
		cin>>j;
		for(int l=1;l<=n;l++){
			int x,y,w;
			cin>>w;
			x=i,y=l,w+=j*2;
			a[++top]={x,y,w};
		}
	}
	sort(a+1,a+top+1,cmp);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=top;i++){
		int x=a[i].x,y=a[i].y,w=a[i].w;
		x=find(x),y=find(y);
		if(x!=y){
			ans+=w;
			fa[x]=y;
//			cout<<x<<" "<<y<<" "<<w<<endl;
		}
	}
	cout<<ans;
	return 0;
}
//road
