#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int t=0;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		t+=z;
	}
	cout<<t;
} 
