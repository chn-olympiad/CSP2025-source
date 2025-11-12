#include<bits/stdc++.h>
using namespace std;
int a[1000];
int b[1000];
int c[100][100];
int main (){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int x;
	for (int i=1 ; i<=n*m ; i++){
		cin >> a[i];
		if (i==1){
			x=a[i];
		}
	}
	for (int j=1 ; j<=n*m ; j++){
		int mx=0;
		for (int k=1 ; k<=n*m ; k++){
			mx=max(a[k],mx);
		}
		for (int l=1 ; l<=n*m ; l++){
			if (mx==a[l]){
				a[l]=0;
				break;
			}
		}
		b[j]=mx;
	}
	int y=1;
	for (int i=1 ; i<=m ; i++){//列 
			if(i%2==1){
				for (int j=1 ; j<=n ; j++){//行 
					c[j][i]=b[y];
					y++;
				}
			}
			if(i%2==0){
				for (int j=n ; j>=1 ; j--){//行 
					c[j][i]=b[y];
					y++;
				}
			} 
	}
	for (int i=1 ; i<=n ; i++){
		for (int j=1 ; j<=m ; j++){
			if (c[i][j]==x){
				cout << j << " " << i;
			}
		}
	}
	
	return 0;
} 