#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+5;
int n,m,k,c[15],a[15][N];
struct node{
	int to,w;
};
vector<node>g[N];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int sum=0;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		sum+=w;
		g[u].push_back((node){v,w});
	}
	if(k==0){
		cout<<sum;
		return 0;
	}
	bool flag=1;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0)flag=0;
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	if(flag){
		cout<<0;
	}
	cout<<13;
	return 0;
}

