#include<iostream>
using namespace std;
int main(){
	int t;
	int n[100];
	int a[100];
	int b[100];
	int c=0;
	cin>>t;
	for(int i=0;i<=t;i++){	
		cin>>n[i];
		for(int j=0;j<=n[i];j++){
			for(int m=0;m<=3;m++){
				cin>>a[m];
				if(a[m]<a[m-1]){	
				b[j]=b-a[m-1]+a[m];	
				}else{
					b[j]=a[m];
				}
			}
			c=c+b[j];
		}
		cout<<c;			
}

	return 0;
}
