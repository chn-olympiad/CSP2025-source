#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int m,n,a[15][15];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			sort(a+1,a+n+1);
			cout<<a[i][j];
		}
	}
	return 0;
} 
