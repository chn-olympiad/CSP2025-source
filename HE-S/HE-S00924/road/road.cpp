#include<bits/stdc++.h>
using namespace std;

int n, m, k;
int a[1000000][10000000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i = 1;i <= m;i++){
		for(int j = 1;j <= k;j++){
			cin>>a[i][j];
		}
	}
	
	for(int i = 1;i<=m;i++){
		if(a[i][j] + a[i+1][j] > a[i+1][j+1]){
			cout<<a[i][j];
		}
	}
	
	if(a[i][j] == 0) continue;
	
	return 0;
}
