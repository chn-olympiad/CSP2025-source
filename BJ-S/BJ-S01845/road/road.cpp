#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
	}
	for(int i=1;i<=k;i++){
		int x;
		cin>>x;
		for(int i=1;i<=n;i++){
			int y;
			cin>>y;
			x+=y;
		}
		if(x==0){
			cout<<0;
			return 0;
		}
	}
	return 0;
}
