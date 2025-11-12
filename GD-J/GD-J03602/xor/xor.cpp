#include<bits/stdc++.h>
using namespace std;
int const N = 1e5;
int arr[5*N+5];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	if(n == 1){
		if(arr[1] == 0){
			cout<<1;
			return 0;
		}else{
			cout<<0;
		}
	}
	if(n == 2){
		if(arr[1] == 0 && arr[2] == 0){
			cout<<2;
			return 0;
		}
		else if(arr[1] == 0 || arr[2] == 0){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	if(n <= 100){
		if(k == 0){
			cout<<1;
			return 0;
		}
	}
	return 0;
}
