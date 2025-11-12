#include<bits/stdc++.h>
using namespace std;
int n,k;
int arr[500003];
int yhh(){
	int sum=0;
	int begin=0,end=0;
	int yh=arr[begin];
	while(end<n){
		if(yh==k){
			end++;
			sum++;
			yh=arr[end];
			begin=end;
			continue;
		}
		end++;
		yh=yh^arr[end];
	}
	return sum;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	if(k==0){
		cout<<n;
		return 0;
	}
	cout<<yhh();
	return 0;
}