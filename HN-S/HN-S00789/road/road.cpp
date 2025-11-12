#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,cnt,fa[100015],a[10015];
struct node{
	int x,y,w;
}e[10000015];
vector<pair<int,int> > v[10015];
unordered_map<int,int> vis[10015];
int find(int x){
	if(x==fa[x]){
		return x;
	}
	return fa[x]=find(fa[x]);
}
bool cmp(node a,node b){
	return a.w<b.w;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+10;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		int x,y,w;
		cin>>x>>y>>w;
		if(x>y){
			swap(x,y);
		}
		if(vis[x].find(y)!=vis[x].end()){
			int pos=vis[x][y];
			v[x][pos].second=min(v[x][pos].second,w);
		}else{
			vis[x][y]=v[x].size();
			v[x].push_back({y,w});
		}
	}
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		for(int j=1;j<n;j++){
			for(int k=j+1;k<=n;k++){
				int dis=a[j]+a[k]+c;
				if(vis[j].find(k)==vis[j].end()){
					vis[j][k]=v[j].size();
					v[j].push_back({k,dis});
				}else{
					int pos=vis[j][k];
					v[j][pos].second=min(v[j][pos].second,dis);
				}
			}
		}
	}
	cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<v[i].size();j++){
			e[++cnt]={i,v[i][j].first,v[i][j].second};
		}
	}
	sort(e+1,e+cnt+1,cmp);
	int sum=0,ans=0;
	for(int i=1;i<=cnt;i++){
		int x=find(e[i].x),y=find(e[i].y);
		if(x!=y){
			fa[x]=y;
			sum++;
			ans+=e[i].w;
			if(sum==n-1){
				cout<<ans;
				return 0;
			}
		}
	}
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
