#include<bits/stdc++.h>
using namespace std;
int arr[10000];
int shape[10000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	long long cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	sort(arr+1,arr+1+n);
	if(n==3){
		cout<<1;
	}
	else if(n==4){
		if(arr[1]+arr[2]+arr[3]>arr[3]*2){
			cnt++;
		}
		if(arr[1]+arr[2]+arr[4]>arr[4]*2){
			cnt++;
		}
		if(arr[1]+arr[3]+arr[4]>arr[4]*2){
			cnt++;
		}
		if(arr[4]+arr[2]+arr[3]>arr[4]*2){
			cnt++;
		}
		if(arr[1]+arr[2]+arr[3]+arr[4]>arr[4]*2){
			cnt++;
		}
		cout<<cnt;
	}
	else if(n==5){
		if(arr[1]+arr[2]+arr[3]>arr[3]*2){
			cnt++;
		}
		if(arr[1]+arr[2]+arr[4]>arr[4]*2){
			cnt++;
		}
		if(arr[1]+arr[2]+arr[5]>arr[5]*2){
			cnt++;
		}
		if(arr[1]+arr[3]+arr[4]>arr[4]*2){
			cnt++;
		}
		if(arr[1]+arr[3]+arr[5]>arr[5]*2){
			cnt++;
		}
		if(arr[1]+arr[4]+arr[5]>arr[5]*2){
			cnt++;
		}
		if(arr[2]+arr[3]+arr[4]>arr[4]*2){
			cnt++;
		}
		if(arr[2]+arr[3]+arr[5]>arr[5]*2){
			cnt++;
		}
		if(arr[2]+arr[4]+arr[5]>arr[5]*2){
			cnt++;
		}
		if(arr[3]+arr[4]+arr[5]>arr[5]*2){
			cnt++;
		}
		if(arr[1]+arr[2]+arr[3]+arr[4]>arr[4]*2){
			cnt++;
		}
		if(arr[1]+arr[2]+arr[3]+arr[5]>arr[5]*2){
			cnt++;
		}
		if(arr[1]+arr[2]+arr[4]+arr[5]>arr[5]*2){
			cnt++;
		}
		if(arr[1]+arr[3]+arr[4]+arr[5]>arr[5]*2){
			cnt++;
		}
		if(arr[3]+arr[2]+arr[4]+arr[5]>arr[5]*2){
			cnt++;
		}
		if(arr[3]+arr[2]+arr[4]+arr[5]+arr[1]>arr[5]*2){
			cnt++;
		}
		cout<<cnt;
	}
	return 0;
} 
