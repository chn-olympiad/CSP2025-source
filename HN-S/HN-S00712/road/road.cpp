#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,r;cin>>n>>m>>r;int x;int y;
	for(int i=1;i<=n*3;i++){
		cin>>x;
	}
	for(int i=1;i<=m*(n+1);i++){
		cin>>y;
	}
	cout<<x/y+3*x;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
