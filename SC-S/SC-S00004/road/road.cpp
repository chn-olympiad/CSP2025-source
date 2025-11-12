#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
struct st{
	int l,r,o;
}a[N];
int v[15][10005],w[15],vis[N];
int n,m,k,minn=INT_MAX;
vector<int> ve[N];
vector<int> ve2[N];
int bfs(int sum,int x,int step){
	if(step==m+1){
		minn=min(minn,sum);
		return minn;
	}
	int mni=INT_MAX;
	for(int i=0;i<ve[x].size();i++){
		if(vis[ve[x][i]]==0){
			vis[ve[x][i]]=1;
			mni=min(mni,bfs(sum+ve[x][i],x,step+1));
			vis[ve[x][i]]=0;
		}
	}
	return mni;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].l>>a[i].r>>a[i].o;
		ve[a[i].l].push_back(a[i].r);
		ve2[a[i].l].push_back(a[i].o);
	}
	for(int i=1;i<=k;i++){
		cin>>w[i];
		for(int j=1;j<=n;j++){
			cin>>v[i][j];
		}
	}
	int minnn=INT_MAX;
	for(int i=1;i<=m;i++){
		minnn=min(minnn,bfs(0,i,0));
	}
	cout<<minnn;
	return 0;
} 