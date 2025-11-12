#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k;
int a[N],sum[N];
int dp[N];

int f(int l,int r){
	return sum[r]^sum[l-1];
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]^a[i];
	}
	if(a[1]==k)dp[1]=1;
	for(int i=2;i<=n;i++){
		dp[i]=dp[i-1];
		for(int j=i-1;dp[j]==dp[i]&&j>0;j--){
			if(f(j+1,i)==k){
				dp[i]=dp[j+1]+1;
				//cout<<j+1<<" "<<i<<'\n'; 
			}
		}
	} 
	cout<<dp[n];
	return 0;
} 
/*
	pow(2,20)=1100000;
	4 2
	2 1 0 3
*/
