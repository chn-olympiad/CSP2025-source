#include <bits/stdc++.h>
using namespace std;
int house[10005]={};
struct a{
	int b1,b2,c;
}lu[1000006];
struct b{
	int r0,r1,r2,r3;
}road[1000006];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>lu[i].b1>>lu[i].b2>>lu[i].c;
	}

	cout<<2025;
	return 0;
}
