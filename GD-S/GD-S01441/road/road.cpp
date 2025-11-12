#include<bits/stdc++.h>
using namespace std;
struct node{
	int u,v,val;
};
int n,m,k;
vector<int> g[12];
node b[1000010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>b[i].u>>b[i].v>>b[i].val;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			int a;
			cin>>a;
			g[i].push_back(a);
		}
	}
	return 0;
}
