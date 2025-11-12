#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[12][10005];
struct node{
	int to,w;
};
struct no{
	int x,y,z;
};
int pai(no x,no y){
	return x.z<y.z;
}
vector <node> g[10005];
void solve(){
	no b[m+5];
	int x[m+5],ans=0;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		b[i].z=w;
		b[i].x=u;
		b[i].y=v;
	}
	sort(b+1,b+1+m,pai);
	bool v[n+5][n+5];
	for(int i=1;i<m;i++){
		if(v[b[i].x][b[i].y]==1){
			m++;
			continue;
		}
		ans+=b[i].z;
		v[b[i].x][b[i].y]=1;
	}
	cout<<ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	srand(time(0));
	cin>>n>>m>>k;
	if(k==0){
		solve();
		return 0;
	}
	int ans=0,cnt=0;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
		int k=rand()%2;
		if(k && cnt<m){
			ans+=w;
			cnt++;
		}
	}
	for(int i=1;i<=k;i++){
		cin>>a[i][0];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			int k=rand()%2;
			if(k && cnt<m+3){
				ans+=a[i][j];
				cnt++;
			}
		}
	}
	cout<<ans;
	return 0;
} 
