#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int u,v,c;
void dfs(int sum,int nam,int name,int num,int sun){
	for(int i=1;i<=sum;i++){
		if(i==sun||i==sum){
			nam=i;
		}else{
			cout<<nam;
			cout<<endl;
		}
	}
	return ;
}
int main(){
	cin>>n>>m>>k;
	cin>>u>>v>>c;
	int a[100][100];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
		}
	}
	dfs(n,m,k,u,v);
	return 0;
}
