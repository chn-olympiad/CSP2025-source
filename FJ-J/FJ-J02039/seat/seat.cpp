#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000],ma[20][20],d[1000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int f=a[1];
	sort(a+1,a+1+n*m);
	int l=0;
	for(int i=m*n;i>=1;i--){
		d[++l]=a[i];
	}
	int sum=0;
	for(int y=1;y<=m;y++){
		if(y%2==1){
			for(int x=1;x<=n;x++){
				ma[x][y]=d[++sum];
			}
		}else{
			for(int x=n;x>=1;x--){
				ma[x][y]=d[++sum];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(ma[i][j]==f){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
