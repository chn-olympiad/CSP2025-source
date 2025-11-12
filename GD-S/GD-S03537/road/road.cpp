#include<bits/stdc++.h>

using namespace std;
struct Node{
	int u;
	int v;
	int w;
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	vector<Node> s(m+1);
	for(int i=1;i<=m;i++){
		cin>>s[i].u>>s[i].v>>s[i].w;
	}
	vector<int> c(k+1,0);
	vector<vector<int> > a(k+1,vector<int>(n+1,0));
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	vector<int> f(k+1,0);
	priority_queue<pair<int,int> > que;

	return 0;
} 
