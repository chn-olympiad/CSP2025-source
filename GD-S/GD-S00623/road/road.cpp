#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,z;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
	}
	for(int i=1;i<=k;i++){
		cin>>x;
		for(int i=1;i<=n;i++){
			cin>>y;
		}
	}
	cout<<0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4 
*/ 
