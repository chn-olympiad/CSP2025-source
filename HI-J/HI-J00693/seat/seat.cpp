#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,zj,xr,cse,sum,sum1;
	cin>>m>>n;
	int cs=m*n;
	int a[cs]={};
	for(int i=0;i<cs;i++){
		cin>>a[i];
	}
	xr=a[0];
	for(int i=0;i<cs;i++){
		for(int j=i+1;j<cs;j++){
			if(a[i]<a[j]){
				zj=a[i];
				a[i]=a[j];
				a[j]=zj;
			}
		}
	}
	//cout<<a[0]<<a[1]<<a[2]<<a[3];
    for(int a1=0;a1<cs;a1++){
    	if(a[a1]==xr){
    	 cse=a1+1;
    }

	}
	//cout<<cse;
	//cout<<a[0]<<a[1];
	if(cse%n==0){
		sum=cse/n;
	}
	else{
		sum=cse/n+1;
	}
	
	if(sum%2==1){
		if(cse%n==0){
	      sum1=n; 
	   }
	   else{
	      sum1=cse%n;
	  }
	}	
	else{
		if(cse%n==0){
	      sum1=1; 
	   }
	   else{
	      sum1=n+1-cse%n;
	  }
	}
	cout<<sum<<" "<<sum1;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
