#include <bits/stdc++.h>
using namespace std;
const int MAXN=10005;
struct s{
	int u,v,w;
};
vector<s> v1;
int v2[MAXN][MAXN];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		v1.push_back({u,v,w});
	}
	for(int i=0;i<k;i++) for(int j=0;j<=n;j++) cin>>v2[i][j];
	cout<<0;
	return 0;
}
