#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	int m=0;
	for(int i=3;i<=n;i++){
		for(int k=0;k<n;k++){
			if(k+i<=n){
				int y=0,q=0;
		    	for(int j=0;j<i;j++){
			 	   y+=a[j];
			 	   if(a[j]>q)q=a[j];
		    	}
		    	if(2*q<y)m+=1;
			}
		}
	}
	cout<<m;
	return 0;
}
