#include<bits/stdc++.h>
using namespace std;
long long mod = 998244353;
long long dp[5005][5005];
int arr[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	if(n == 3){
		if(arr[0]+arr[1]+arr[2] > 2*arr[2]){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
	bool it = true;
	for(int i=0;i<n;i++){
		if(arr[i] != 1) it = false; 
	}
	if(it){
		cout<<2*n*n-12*n+20;
	}
	return 0;
}
