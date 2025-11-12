#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
struct COUNTRY{
	int x,v[10001];
}a[11];
struct ROAD{
	int v,w;
}s;
vector<vector<ROAD > > road;
int dp[10001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long q=0;
	int n,m,k;//分别表示原有的城市数量、道路数量和准备进行城市化改造的乡镇数量。
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;//两座城市及费用
		cin>>u>>v>>w;
		road[u].back().v=v;
		road[u].back().w=w;
		q+=w;
	}
	for(int i=1;i<=k;i++){
		cin>>a[i].x;
		for(int j=1;j<=n;j++){
			cin>>a[i].v[j];
		}
	}
	cout<<q;
	return 0;
}
