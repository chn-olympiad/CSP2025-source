#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n , m ;
	cin >> n >> m ;
	int a[10000] ;
	for(int i = 0 ; i < m*n ; i++){
		cin>>a[i];
	}
	int r = a[0] ;
	int wa[10000];
	sort(a,a+n*m);
	for(int i = 0 ; i < n*m ; i++){
		wa[i]=a[n*m-1-i];
	}
	int t ;
	for(int i = 0 ; i < n*m ; i++){
		if(wa[i]==r){
			t=i+1;
		}
	}
	if(t/m%2!=0){
		if(t%m==0){
			cout<<t/m<<' '<<m;
		}
		else{
			cout<<t/m+1<<' '<<m-t%m+1; 
		}
	}
	if(t/m%2==0){
		if(t%m==0){
			cout<<t/m<<' '<<1;
		}
		else{
			cout<<t/m+1<<' '<<t%m; 
		}
	}
}

