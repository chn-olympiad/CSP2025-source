#include<bits/stdc++.h>
using namespace std;
int n,m,t=0,y=0,a[105],b[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
	 	cin>>a[i];
	}
	y=a[1];
	for(int i=2;i<=n*m;i++){
	 	if(a[i]>a[i-1]){
	 		t+=a[i-1];
	 		a[i-1]=a[i];
	 		a[i]=t;
	 		t=0;
		}
	}
	for(int i=1;i<=n;i++){
	 	for(int j=1;j<=m;j++){
	 		for(int x=1;x<=m*n;x++){
	 			b[i][j]=a[x];
	 			if(b[i][j]==y){
	 				cout<<i<<" "<<j; 
				}
			}
		}
	}
	return 0;
}