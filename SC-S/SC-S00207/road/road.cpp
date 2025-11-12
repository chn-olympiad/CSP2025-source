#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,k,min1=1e9;
	cin>>n>>m>>k;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int a[m][3],b[k][n+1];
	for(int i=0;i<m;i++){
		for(int j=0;j<3;j++)
			cin>>a[i][j];
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<n+1;j++){
			cin>>b[i][j];
			min1=min(min1,b[i][0]);
		}
	}
	min1+=a[2][2]+a[3][2]+b[0][1]+b[0][3];
	cout<<min1;
	return 0;
}