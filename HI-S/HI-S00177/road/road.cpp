#include<bits/stdc++.h>
using namespace std;
vector<int> a[1000100];
int v[1000100];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;cin>>n>>m>>k;
	for(int i=1;i<=m;i++) {
		int x,y;cin>>x>>y>>v[i];
		a[x].push_back(y);
		a[y].push_back(x);
	}
	
 return 0;
}

