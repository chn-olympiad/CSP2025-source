#include<bits/stdc++.h>
using namespace std;
int a[105];
int b[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int xr=a[1];
	sort(a+1,a+n*m+1);
	int js=n*m;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				b[j][i]=a[js--];
			}
		}
		else{
			for(int j=n;j>=1;j--){
				b[j][i]=a[js--];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==xr){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}


	return 0;
}
