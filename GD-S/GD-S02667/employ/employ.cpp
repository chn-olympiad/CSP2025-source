#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	int d[n];
	vector<int> c[n];
	for(int i=0;i<n;i++) cin>>d[i];
	for(int i=0;i<n;i++) cin>>c[i];
	vector<bool> visit(n,false);
	int res=dfs(n,0,visit);
	return n;
}
