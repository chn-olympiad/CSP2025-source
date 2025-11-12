#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+1000;
int n,m,k;
struct node{
	int w;
	int pre;
	int to;
}edge[N];
int val[20];
int fa[100000];
int cnt=0;
void add(int u,int v,int w){
	cnt++;
	edge[cnt].pre=u;
	edge[cnt].to=v;
	edge[cnt].w=w;
}
bool cmp(node x,node y){
	return x.w<y.w;
}
bool flaga=1;
int dis[10005];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	int u,v,w;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		add(u,v,w);
	}
	int expoi=0;
	for(int i=1;i<=k;i++){
		expoi++;
		cin>>val[i];
		if(val[i]!=0) flaga=0;
		for(int j=1;j<=n;j++){
			cin>>dis[j];
			if(v!=0){
				flaga=0;
			}
		}
		for(int j=1;j<=n;j++){
			for(int k=1;k<=j-1;k++){
				if(j!=k) add(j,k,dis[j]+dis[k]);
			}
		}
	}
	sort(edge+1,edge+cnt+1,cmp);
	int need=n-1;
	int now=0;
	if(flaga&&k!=0){
		int ans=0;
		while(need){
			now++;
			int pone=edge[now].pre,ptwo=edge[now].to;
			if(fa[pone]==fa[ptwo]){
				continue;
			}
			else{
				fa[pone]=fa[ptwo];
				ans+=edge[now].w;
				need--;
			}
		}
		cout<<ans;
		return 0;
	}
	int ans=0;
	while(need){
		now++;
		int pone=edge[now].pre,ptwo=edge[now].to;
		if(fa[pone]==fa[ptwo]){
			continue;
		}
		else{
			fa[pone]=fa[ptwo];
			ans+=edge[now].w;
			need--;
		}
	}
	cout<<ans;
	return 0;
} 
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/
