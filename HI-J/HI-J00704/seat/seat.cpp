#include <iostream>
using namespace std;
int main(){
	long long n,m,a[100],min,b=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	min=a[1];
	
	for(int i=1;i<=m*n;i++){
		for(int j=i;j<=m*n;j++){
			if(a[i]<a[j]){
				b=a[i];
				a[i]=a[j];
				a[j]=b;
			}
		}
	
		
	}
	

	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				if(a[(i-1)*m+j]==min){
					cout<<i<<" "<<j;
				}	
				
			}
		}else{
			for(int j=m;j>=1;j--){
			
				if(a[(i-1)*m+m-j+1]==min){
					cout<<i<<" "<<j;
				}
				
			}
		}
	}
	return 0;
} 
