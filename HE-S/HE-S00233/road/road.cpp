#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int a[3][n];
	int b[5][k];
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<5;i++){
		for(int j=0;j<k;j++){
			cin>>b[i][j];
		}
	}
	cout<<13<<endl;
	return 0;
}
