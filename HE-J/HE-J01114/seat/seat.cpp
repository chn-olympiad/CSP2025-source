#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[1000000][1000000],n,m;
	cin>>n>>m;
	for(int i;i<n;i++){
		for(int j;j<m;j++)
			cin>>a[i][j];	
	cout<<a[i][j];
	}
	return 0;
}
