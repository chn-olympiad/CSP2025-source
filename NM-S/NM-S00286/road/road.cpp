#include<bits/stdc++.h>
using namespace std;

const int N = 1e4;

int n,m,k;
int info[N][N];
int slove(){
	int tmp[N][N];
	int res;
	for(int i=0;i<m+1;i++){
		for(int j=0;j<j+m+1;j++){
			tmp[i][j] = max(info[i][j],info[i][j]+info[i+1][j]);		
		}
	}
	for(int i=0;i<n;i++){
		for(int i=0;i<m;j++){
			res += temp[i][j];
		}
	}
	return res;
}

int main(){
	int res;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	res = solve();
	cout << res;
	return 0;
}
