#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct eg{
	int u,v,w;
}; 
struct xc{
	int c;
	vector<int> a;
};
eg a[1001000];
xc c[11];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i],w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i].c;
		c[i].a.push_back(0);
		for(int j=1;j<=n;j++){
			int x;
			cin>>x;
			c[i].a.push_back(x);
		}
	}
	
	return 0;
}

