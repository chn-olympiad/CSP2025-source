#include<bits/stdc++.h>
using namespace std;
int a[20000],zw[2000][2000],m,n;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int xr=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];	
	}
	xr=a[1];
	sort(a+1,a+n*m+1,cmp);
	int yyy=1;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			zw[i][j]=a[yyy];
			yyy++;
		}
		if((i+1)<=m){
			i++;
			for(int j=n;j>=1;j--){
				zw[i][j]=a[yyy];
				yyy++;
			}	
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(zw[i][j]==xr){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}
