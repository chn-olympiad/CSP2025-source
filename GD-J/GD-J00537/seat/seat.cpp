#include<bits/stdc++.h>
using namespace std;
int seat[15][15],a[225],n,m,xm,ans;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1; i <= n*m; i++){
		cin>>a[i];
		if(i==1) xm=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i = 1; i <= m; i++){
		if(i%2==1){
			for(int j = 1; j <= n; j++){
				seat[j][i]=a[(i-1)*n+j];
			}
		}else{
			for(int j = n; j >= 1; j--){
				seat[j][i]=a[i*n-j+1];
			}
		}
	}
	for(int i = 1; i <= m; i++){
		//cout<<endl;
		for(int j = 1; j <= n; j++){
			//cout<<seat[i][j]<<' '; 
			if(seat[i][j]==xm){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
}
