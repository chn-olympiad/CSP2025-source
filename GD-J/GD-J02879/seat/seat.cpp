#include<bits/stdc++.h>
using namespace std;
int a[1005][1005],d[1005][1005];
int n,m;
void init(){
	for(int k=1;k<=n*m-1;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
		       if(j==m){
		       	  	if(a[i][j]<a[i+1][1])swap(a[i][j],a[i+1][1]);
			   }else{
					if(a[i][j]<a[i][j+1])swap(a[i][j],a[i][j+1]);   	  
			   }	
			}
		}
	}
}
int main(){
	int X;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> a[i][j];
			if(i==1&&j==1)X=a[i][j];
		}
	}
	init();
	for(int j=1;j<=m;j++){
		if(j%2){
	 		for(int i=1;i<=n;i++){
				d[i][j]=a[j][i];
			}
		}else{
			for(int i=n;i>=1;i--){
				if(i==1){
					d[i][j]=a[i+1][j];
					continue;	
				}
	 		 	d[i][j]=a[i][j-1];
			}
		}
	}
	for(int i=1;i<=n;i++){
	 	for(int j=1;j<=m;j++){
	 		 if(d[i][j]==X)
	 		 	cout << j << " "<<i;
	 		 
		}
	}
}
