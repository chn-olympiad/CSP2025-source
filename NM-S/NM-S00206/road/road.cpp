#include<bits/stdc++.h>

using namespace std;

const int N = 2e8 +100;
const int N2 = 1e4+100;
const int INF = 2e9;
struct node{
	int u,v,w;
}edge[N];
int va[N];
int dis[N][N2];
int s[N];
bool cmp(node x,node y){
	return x.w<y.w;
}
int find_set (int x){
	if(x!=s[x]) return s[x]=find_set(s[x]);
	else return s[x];
}
void solve(){
	int n,m,k;
	cin >> n >> m >>k;
	for(int i=1;i<=n;i++){
		int u,v,w;
		cin >> edge[i].u >> edge[i].v >> edge[i].w;
	}
	memset(dis,INF.sizeof dis);
	for(int i=1;i<=k;i++){
		int x;
		cin >> x;
		for(int g=1;j<=n;j++){ cin >> va[i];
			for(int k=j+1;k<=n;k++){
				for(int k=j+1;k<=n;k++) dis[j][k]=min(dfs[j][k],val[j]+val[k]+x);
			}
		}
	}
	int id=m;
    for(int i=1;i<=n;i++){
       	for(int j=1;j<=n;j++){
       	    id++;
       		edge[id].u=i;
			edge[id].v=j;
		    edge[id].w=dis[i][j];
		}
	}
	for(int i=1;i<=n;i++) s[i]=i;
	sort(edge+1,edge+id+1,cmp);
	int num=0,ans=0;
	for(int i=1;i<=id;i++){
		node now=edge[i];
		int u=now.u;
		int v=now.v;
		int w=now.w;
		if(find_set(u)!=find_set(v)){
			s[u]=s[find_set(v)];
			num++;
			cout << now.m << " ";
			ans+=w;
		}
		if(num==n-1){
			break;
		} 
	}
	cout << ans;
}
int main(){
    freopen("road.in","r",stdin);
	freopen("road .out","w",stdout);
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
