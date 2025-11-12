#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
struct node{
	long long to,val,id;
	bool operator < (const node x)const{
		return val>x.val;
	}
};
vector<node> ve[N];
priority_queue<node> q;
long long m,n,k,p[15][N],c[15];
bool vis[15],vis1[N],flagA=1;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		ve[u].push_back({v,w});
		ve[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0){
			flagA=0;
		}
		for(int j=1;j<=n;j++){
			cin>>p[i][j];
		}
	}
	vis1[1]=1;
	long long cnt=1,ans=0;
	for(int i=1;i<=k;i++){
		for(int j=2;j<=n;j++){
			q.push({j,p[i][j]+p[i][1]+c[i],i});
		}
	}
	for(auto it:ve[1]){
		q.push({it.to,it.val,0});
	}
	while(!q.empty()&&cnt!=n){
		while(!q.empty()&&vis1[q.top().to])q.pop();
		node u=q.top();
		q.pop();
		vis1[u.to]=1;
		if(vis[u.id])u.val-=c[u.id];
		vis[u.id]=1;
		cnt++;
		ans+=u.val;
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				if(vis1[j])continue;
				q.push({j,p[i][j]+p[i][u.to]+c[i],i});
			}
		}
		for(auto it:ve[u.to]){
			q.push({it.to,it.val,0});
		}
	}
	cout<<ans;
	return 0;
}

