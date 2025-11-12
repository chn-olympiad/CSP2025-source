#include<bits/stdc++.h>
using namespace std;
int n,m,z=1,js;
int a[200];
int b[20][20];
int cmp(int n,int m){
	return n>m;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	js=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				b[j][i]=a[z];
				z++;
			}			
		}
		else{
			for(int j=1;j<=n;j++){
				b[j][i]=a[z];
				z++;
			}			
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(b[i][j]==js){
				cout<<j<<" "<<i;
				return 0; 
			}	
		}
	}
	return 0; 
} 

