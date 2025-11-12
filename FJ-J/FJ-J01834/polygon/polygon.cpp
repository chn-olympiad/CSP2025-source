#include <bits/stdc++.h>
using namespace std;

long long dp[5000]={};
int n;
int nums[5000]={};
int save[5000]={};

int b(int a,int b){
	return a>b;
}


int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>nums[i];
	}
	sort(nums,nums+n,b);
	for(int i=2;i<n;i++){
		int count=0;
		for(int j=i-1;j>=0;j--){
			save[i-j-1]=nums[j]+nums[i];
			for(int k=i-j-3;k>=0;k++){
				if(save[k]+nums[j]>nums[k]*2){
					count+=k+1;
					break;
				}
			}
		}
		dp[i]=dp[i-1]*2+count;
	}
	cout<<dp[n-1]%998%353%244;
	return 0;
}
