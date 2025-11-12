#include<bits/stdc++.h>
using namespace std;
bool panduan(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[105]={0};
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+n*m+1,panduan);
	int dp[11][11]={0};
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dp[i][j]=a[i+(j-1)*n];	
		}	
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(dp[i][j]==r){
				if(j%2==1){
					cout<<j<<" "<<i;
					return 0;
				}else{
					cout<<j<<" "<<n-i+1;
					return 0;
				}
			}
		}
	}
}
