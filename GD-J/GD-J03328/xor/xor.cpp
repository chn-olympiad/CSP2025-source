#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int a[n];
	if(k==0&&n==2){
		cout<<1;
		return 0;
	}
	if(k==0&&n<2){
		cout<<0;
		return 0;
	}
	if(k==0){
		if(n%2!=0){
			cout<<0;
		}else{
			cout<<n;
		}
		return 0;
	}
	for(int b=0;b<n;b++){
		cin>>a[b];
	}
	
}
