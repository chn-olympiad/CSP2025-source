#include<bits/stdc++.h>
using namespace std;
int a[5000],n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
		if(flag){
			if(a[i]!=1){
				if(a[i]<=100){
					flag=0;
				}
				flag=0;
			}
		}
	}
	if(n==3){
		int mymax=max(a[1],a[2]);
		mymax=max(mymax,a[3]);
		int mysum=a[1]+a[2]+a[3];
		if(mysum>2*mymax){
			cout<<1;
		}
		else{
			cout<<0;
		}
		return 0;
	}
	if(flag==1){
		int m=n-3+1,mysum=0;
		for(int i=1;i<=m;i++){
			mysum+=i;
		}
		cout<<mysum;
		return 0;
	}
	if(flag==0){
		
		int mycount=0;
		for(int i=1;i<=n-3;i++){
			for(int j=i+3;j<=n;j++){
        		int mymax=0,mysum=0;
        		for(int k=i;k<=j;k++){
	    	    	mymax=max(mymax,a[k]);
		    	    mysum+=a[k];
	        	}
	        	if(mysum>2*mymax){
	        		mycount++;
				}
			}
		}
		cout<<mycount*3/2;
		return 0;
	}
} 
