#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen(number.in,r,stdin);
	freopen(number.out,w,stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m]={};
	int x=0;
	int c=0;

	for(int i=0;i<n*m;i++){
		cin>>a[i];
		
    }c=a[0];
    



	for(int i=0;i<n*m;i++){
    	for(int j=i;j<n*m;j++){
    		if(a[i]>a[i+1] ){
	    		x=a[i+1];   //ц╟ещ 
				a[i+1]=a[i];
				a[i]=x;
			}
    	
		}
	}
	
	
	
	for(int i=n*m-1;i>=0;i--){
		cout<<a[i];
		if(c==a[m*n-i]){
			
		}

	}

}
