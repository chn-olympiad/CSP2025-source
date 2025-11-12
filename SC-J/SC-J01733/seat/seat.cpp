#include<bits/stdc++.h>
using namespace std;

int n,m,a[101],r,z[11][11];

int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1);
	int k=n*m;
	for(int i=1; i<=n; i++){
		if(i%2==0){
			for(int j=m; j>=1; j--){
				z[i][j]=a[k];
				k--;
			}
		}
		else{
			for(int j=1; j<=m; j++){
				z[i][j]=a[k];
				k--;
			}
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(z[i][j]==r){
				cout<<i<<' '<<j;
				break;
			}
		}
	}
	
	return 0;
}