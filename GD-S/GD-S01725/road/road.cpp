#include<bits/stdc++.h>
using namespace std;
const int N=1e4+1;
struct poi{
	int to,w;
};
vector<poi> t[N];
int c[11],a[11][N],n,m,k,d[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=2;i<=n;i++)d[i]=3e16;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		t[u].push_back({v,w});
		t[v].push_back({u,w}); 
	}
	bool flag=0;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cout<<a[i][j];
			if(a[i][j]!=0)flag=1;
		}
		if(c[i]!=0)flag=1;
	}
	if(!flag)cout<<0;
	return 0;
}
