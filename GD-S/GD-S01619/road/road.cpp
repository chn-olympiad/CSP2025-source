#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
struct tt{
	int to,w;
};
vector<tt> e[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,k,s=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
		s+=w;
	}
	while(k--){
		int a;
		cin>>a;
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
		}
	}
	cout<<s;
	return 0; 
	//第二题诗人？ 
} 
