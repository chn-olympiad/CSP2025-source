#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],b[105],x[105][105],num,k=1;
bool bo(int x1,int x2){
	return x1>x2;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		b[i]=i;
		k++;
	}
	num=a[1];
	sort(a+1,a+k,bo);
	for(int i=1;i<=n*m;i++){
		int c=(b[i]-1)/n+1;
		if(c%2==1){
			if(b[i]%n){
				x[c][b[i]%n]=a[i];
			}
			else{
				x[c][n]=a[i];
			}
		}
		else{
			if(b[i]%n){
				x[c][n-b[i]%n+1]=a[i];
			}
			else{
				x[c][1]=a[i];
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(x[i][j]==num){
				cout<<i<<" "<<j;
				return 0;
			}
		}
    }	
	return 0;
} 
