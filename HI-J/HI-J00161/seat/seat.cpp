#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat1.in","r",stdin);
	freopen("seat1.out","w",stdout);
	int n,m,seat[10][10];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1],z=n*m;
	sort(a+1,a+n*m+1);
	
	for(int i=1;i<=m;i++){//ап 
		if(i%2==1){
			for(int j=1;j<=n;j++){
				seat[j][i]=a[z];
				z--;
			}
		}
		else if(i%2==0){
			for(int j=n;j>=1;j--){
				seat[j][i]=a[z];
				z--;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(seat[i][j]==r){
				cout<<j<<" "<<i;
			}
		}
	}
	return 0;
}
