#include<bits/stdc++.h>
using namespace std;

int f(int arr[],int l,int r){
	bool t[1100000];
	for(int i=0;i<=1100000;i++){
		t[i]=0;
	}
	int max=0;
	for(int i=0;i<r-l+1;i++){
		int j=0;
		while(1){
			if(arr[i]==0) break;
			t[j]=arr[i]%2||t[j];
			arr[i]=arr[i]/2;
			j++;
			if(max<j) max=j;
		}
	}
	int ans=0;
	for(int i=0;i<max;i++){
		ans=pow(2,i)*int(t[i]);
	}
	return ans;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n>>k;
	int arr[n];
	int ans=0;
	for(int i=0;i<n;i++) cin>>arr[i];
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(f(arr,i,j)==k){
				if(j-i+1>ans){
					ans=j-i+1;
					cout<<j<<i;
				}
			}
		}
	}
	cout<<ans;
}

