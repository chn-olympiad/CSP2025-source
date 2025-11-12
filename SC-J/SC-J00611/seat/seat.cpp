#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],seat[15][15];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	cin>>n>>m;
	int x=n*m;
	for(int i=1;i<=x;i++){
		cin>>a[i];
	}
	int f=a[1];
	sort(a+1,a+1+x,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				seat[j][i]=a[(i-1)*n+j];			
			}
		}
		else{
			for(int j=n;j>=0;j--){
				seat[j][i]=a[(i-1)*n+n-j+1];
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(seat[i][j]==f){
				cout<<j<<" "<<i<<endl;
			}
		}
	}
	return 0;
} 