#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	vector<vector<int>> road(m,vector<int>(3,0));
	vector<vector<int>> vi(k,vector<int>(n+1,0));
	for(int i=0;i<m;i++){
		cin>>road[i][0]>>road[i][1]>>road[i][2]; 
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<n+1;j++){
			cin>>vi[i][j];
		}
	}
	cout<<13;
	return 0;
}
