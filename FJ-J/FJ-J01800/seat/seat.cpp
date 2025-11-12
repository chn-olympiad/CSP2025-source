#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],ans=1,_n,_m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin >> n >> m ;
    int sum=n*m;
    for(int i=1;i<=sum;i++)cin >> a[i] ;
    sort(a+2,a+sum+1);
    for(int i=sum;i>=2;i--){
    	if(a[1]<a[i]){
    		ans++;
		}else{
			break; 
		}	 
	}	
	if(ans%n==0){
	    _m=ans/n;	
	}else{
		_m=ans/n+1;
	}
	_m=(_m%2+_m/2)*2;
	_n=ans%(2*n);
	if(_n==0){
		_n=2*n;
	}
	if(_n<=n){
	    _m--;	
	}else{
	    _n=(_n-n*2-1)*-1;
	    
	}
	cout << _m <<" "<< _n ;
	return 0;
} 
