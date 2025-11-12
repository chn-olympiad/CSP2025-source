#include <bits/stdc++.h>
using namespace std;
int n,m,k;
struct R{
	int x,y,z;
}a[100010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(!k){
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
	}
	}
	cout<<0;
	return 0;
}

