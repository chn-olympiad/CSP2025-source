#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[120];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<=n*m-1;i++){
			cin>>a[i];
	}
	int j=1,h=1;
	for(int i=0;i<=n*m-1;i++){
		if(a[0]>a[i]){
			if( h%2==1){
				j=j+1;
				if(j>n){
					h=h+1;
					j=n;
				}
			}
			if( h%2==0){
				j=j-1;
				if(j<1){
					h=h+1;
					j=1;
				}
			} 
		}
		
	}
	cout<<j<<" "<<h; 
	
	return 0;
}
