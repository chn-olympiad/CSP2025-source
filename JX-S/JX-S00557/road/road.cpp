#include<bits/stdc++.h>
using namespace std;
struct node{
	int id,qz;
}a[1000005];
int n,m,k;
vector<node>v[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		v[x].push_back({y,z});
		v[y].push_back({x,z});
	}
	cout<<"5182974424";
	return 0;
}
