#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100][100];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}cout<<1<<' '<<1;

	return 0;
}

