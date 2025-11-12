#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int a[10001][10001],ans;
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i =1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		ans+=z;
	}
	cout<<ans;
	return 0;
}


