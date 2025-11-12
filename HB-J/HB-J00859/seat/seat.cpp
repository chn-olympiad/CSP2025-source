#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","W",stdout);
	int a[15][15];
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}	
	}sort(a+1,a+n+1);
	int b=a[1][1];
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==b){
				cout<<a[i][j];			
			}
		}
	}
	return 0;
}
