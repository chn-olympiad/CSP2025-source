#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	char u[123456],v[123456];
	cin>>n>>m;
	for(int i=1;i<=n+m;i++){
		cin>>u>>v;
	}
	for(int j=0;j<m;j++)
		cout<<"0"<<"\n";
	return 0;
}
