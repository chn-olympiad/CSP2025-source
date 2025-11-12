#include <bits/stdc++.h>
using namespace std;
long long n,k;
long long a[10000]; 
long long sum1=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long h=0;h<n;h++){
		cin>>a[h];
	}
	long long kai=0;
	long long sum0=0;
	long long wei=-1;
	long long io=-1;
	for(long long kai=wei+1;kai<n;kai++){
		sum0=a[kai];
		if(sum0==k){
			sum1++;
		}else{
			for(long long kai1=kai+1;kai1<n && kai1>io;kai1++){
		    	if(sum0==0|| a[kai1]==0 && sum0%2!=0 || a[kai1]%2!=1){
		    		sum0=sum0^a[kai1]-1;
				}else sum0=sum0^a[kai1];
		    	if(sum0==k){
		    	    sum1++;
		    	    wei=kai1;
		    	    io=kai1;
		    	    break;
				}
			}
		}
	    
	}
	cout<<sum1;
	return 0;
}
