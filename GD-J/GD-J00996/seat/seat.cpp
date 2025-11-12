#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[15][15];
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	int n,m,b,c=0;
	cin>>n>>m;
	int f= 1,g=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			if(i==1&&j==1){
				b= a[1][1];
			}
	}} 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==b){
				if((n*m-i+1)/2>0)
					cout<<(n*m-i+1)/2<<" "<<i;
				else{
					cout<<((n*m-i+1)/2)-1<<" "<<i;
				}
			}
		}
		
	}
	
} 
