#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int dp[100000]={0};
long long n,h;
int fun(int k){
	int sum=a[k];
	while(k<=n&&sum!=h){
		sum^=a[k+1];
		k++;
	}
	return k;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	dp[n]=0;
	cin>>n>>h;
	if(h==0){
		cout<<1;
		return 0;
	} 
	if(h==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>0;i--){
		dp[i]=max(dp[i+1],1+dp[fun(i)]);
	}
	cout<<dp[1];
}
