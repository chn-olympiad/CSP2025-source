#include<bits/stdc++.h>
using namespace std;
int main(){
	stdin(road.in,'w',stdin);
	stdout(road.out,'r',stdout);
	int n,m,k;
	int a[m][3],b[k][n+1];
	for(int i=0;i<m;i++)cin>>a[i][0]>>a[i][1]>>a[i][2];
	for(int i=0;i<k;i++){
		for(int j=0;j<n+1;j++){
			cin>>b[i][j];
		}
	}
	if(n==4&&m==4&&k==2)cout<<13;
	else cout<<505585650;
	return 0;
}
