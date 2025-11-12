#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen(seat.in,"r",stdin);
	freopen(seat.out,"w",stdout);
	int m,n,z,z1=0,x=1;
	cin>>m>>n;
	int a[105][105],b[m*n+2];
	for(int i=1;i<=m*n;i++){
		cin>>b[i];
		z=b[1];
	}
	for(int i=1;i<=n;i++){
		if(i%2==0){
			for(int j=m;j>=1;j--){
				a[i][j]=x;
				x++;
			}
		}
		else{
			for(int j=1;j<=m;j++){
				a[i][j]=x;
				x++;
			}
		}
	}
	sort(b+1,b+1+m*n);
	for(int i=m*n;i>=1;i--){
		z1++;
		if(b[i]==z){
			for(int j=1;j<=n;j++){
				for(int k=0;k<=m;k++){
					if(a[k][j]==z1) cout<<k<<" "<<j;
				}
			}
		}
	}
	return 0;
}
