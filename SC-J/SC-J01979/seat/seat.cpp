#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c,r,aa;
	cin>>n>>m;
	int a[m][n];
	cin>>aa;
	for(int i=1;i<=m*n;i++){
		for(int j=i;i<=m*n;j++){
			cin>>a[i-1][j-1];
			if(a[i][j]){
				
			}
		}	
	}
	for(int i=1;i<=m*n-1;i++){
		for(int j=i;i<=m*n;j++){
			if(aa==a[i][j]){
				cout<<1<<" "<<1;
			}
			else if(aa<=a[i][j]){
				c==r;
			}
		}
 	}
 	cout<<1<<" "<<2;
	return 0;
} 