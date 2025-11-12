#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105],seat[15][15],num;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	num=a[1];
	sort(a+1,a+1+n*m);
	//seat[ÁÐ][ÐÐ] 
	int count=n*m;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				seat[i][j]=a[count];
				count--;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				seat[i][j]=a[count];
				count--;
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(seat[i][j]==num){
					cout<<i<<" "<<j;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				if(seat[i][j]==num){
					cout<<i<<" "<<j;
				}
			}
		}
	}
	return 0;
} 
