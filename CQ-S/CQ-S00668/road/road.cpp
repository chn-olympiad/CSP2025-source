#include<bits/stdc++.h>
using namespace std;
struct node{
	int nxt,v;
};
vector<node>g[10010];
int cost[15];
int a[15][10010];
int sum[10010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int ans=0;
	for(int i=1;i<=m;i++){
		int x,y,val;
		cin>>x>>y>>val;
		g[x].push_back({y,val});
		g[y].push_back({x,val});
		ans+=val;
	}
	int flag=0;
	for(int i=1;i<=k;i++){
		cin>>cost[i];
		sum[i]+=cost[i]; 
		if(cost[i]!=0) flag=1;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]!=0) flag=1;
			sum[i]+=a[i][j];
		}
	} 
	sort(sum+1,sum+k+1);
	if(!flag) cout<<"0";
	else{
		cout<<min(ans,sum[1]);
	}
	return 0;
}

