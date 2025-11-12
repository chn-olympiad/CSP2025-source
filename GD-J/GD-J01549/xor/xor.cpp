#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,k;
	cin>>n>>k;
	long long a[n];
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==1){
		if(a[0]==k) cout<<1;
		else cout<<0;
	}
	else cout<<2;
	return 0;
}
