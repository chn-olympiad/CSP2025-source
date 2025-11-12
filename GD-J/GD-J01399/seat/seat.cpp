#include<bits/stdc++.h>
using namespace std;
int n,m,seat[101][101];
int a[100001];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int num=a[1];
	int id=n*m;
	sort(a,a+n*m+1);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				seat[j][i]=a[id];
				id--;
			}	
		}
		else{
			for(int j=n;j>=1;j--){
				seat[j][i]=a[id];
				id--;
			}	
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(seat[i][j]==num){
				cout<<j<<" "<<i;
			}
		}
	}
	return 0;
}
