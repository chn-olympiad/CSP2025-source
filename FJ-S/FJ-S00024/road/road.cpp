#include<bits/stdc++.h>
using namespace std;
#define long long int
const int N = 1e6+5;
//vecotr<int>edge(N);
//int w[N][N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int arr[k+3][n+3];
	for(int i = 0;i<m;i++){
		int x,y,z;
		cin>>x>>y>>z;
	//	edge[x].push_back(y);
	//	edge[y].push_back(x);
	}
	for(int i = 1;i<=k;i++){
		for(int j = 0;j<=n;j++){
			cin>>arr[i][j];
		}
	}
	cout<<arr[1][0];
	return 0;
}
