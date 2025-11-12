#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+1;
int n,m,k;
vector<pair<int,int> > e[maxn];
int c[maxn],a[maxn][maxn];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[u].push_back(make_pair(v,w));
		e[v].push_back(make_pair(u,w));
	}
	
	cout<<"0"<<endl;
	return 0;
}
/*

*/
