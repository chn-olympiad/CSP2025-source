#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","W",stdout);
	int n,max=0,sum=0,m=0,q=0;
	int a[5500]={};
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		for(int j=0;j<=n-i;j++){
			q=0;
		   for(int b=0;b<=n-i-j;b++){
		   	q+=b;
		   }
		   	for(int b=0;b<q;b++){
		   	   sum=0,max=0;
		   	 for(int c=j;c<j+i;c++){
		   	 	sum+=a[c];
		        if(a[c]>max){
		        	max=a[c];
		        }
	           }
	           if(sum>(2*max)){
	    	   m++;
	           }
		   }
		}	
		}
		cout<<m;
	return 0;
}
