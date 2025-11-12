#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=500005;
int n,k,A[MAXN];
void solve1(){
	int ans=0;
	if(k==0){
		for(int i=1;i<=n;i++){
			if(A[i]==0) ans++;
			else if(A[i+1]==1) ans++,i++;
		}
	}else{
		for(int i=1;i<=n;i++) ans+=(A[i]==1);
	}
	cout<<ans<<endl;
}
int dp[MAXN];
void solve2(){
	for(int i=1;i<=n;i++){
		int sum=0;
		dp[i]=dp[i-1];
		for(int j=i;j>=1;j--){
			sum^=A[j];
			if(sum==k){
				dp[i]=max(dp[i],dp[j-1]+1);
				break;
			}
		}
	}
	cout<<dp[n]<<endl;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool isab=true;
	for(int i=1;i<=n;i++){
		scanf("%d",&A[i]);
		if(A[i]>1) isab=false;
	}
	if(isab) solve1();
	else solve2();
	return 0;
} 
