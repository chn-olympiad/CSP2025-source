#include<bits/stdc++.h>
using namespace std;
#define min(x,y) x<y?x:y
#define max(x,y) x<y?y:x
struct node{
	int x,y,z;
};
bool cmp(node x,node y){
	return x.z<y.z;
}
int fa[10005],sz[10005];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(sz[fx]<sz[fy])fa[fx]=fy,sz[fy]+=sz[fx];
	else fa[fy]=fx,sz[fx]+=sz[fy];
}
int val[10005][10005];
signed main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i,sz[i]=1;
	vector<node>ve;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)val[i][j]=2e9+1;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		val[min(x,y)][max(x,y)]=z;
	}
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		vector<int>vve;
		for(int j=1;j<=n;j++){
			int x;
			cin>>x;
			vve.push_back(x);
		}
		for(int x=1;x<=n;x++)
			for(int y=x+1;y<=n;y++)
				val[x][y]=min(val[x][y],vve[x-1]+vve[y-1]);
	}
	for(int x=1;x<=n;x++)
		for(int y=x+1;y<=n;y++)
			if(val[x][y]<2e9+1)
				ve.push_back({x,y,val[x][y]});
	sort(ve.begin(),ve.end(),cmp);
	long long cnt=0,ans=0;
	for(int i=0;i<ve.size();i++){
		if(cnt==n-1)break;
		int fx=find(ve[i].x),fy=find(ve[i].y),z=ve[i].z;
		if(fx==fy)continue;
		merge(fx,fy);
		cnt++;
		ans+=z;
	}
	cout<<ans;
	return 0;
}