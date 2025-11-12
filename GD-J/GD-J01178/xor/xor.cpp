#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,k,aaa,ans;
unordered_map<int,int>mapp;
int arr[N];
int dp[N][2];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	for(int i=0;i<N;i++)arr[i]=LLONG_MAX;
	mapp[0]=0;
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		int tmp;
		scanf("%lld",&tmp);
		aaa^=tmp;
		if(k){
			mapp[aaa]=max(mapp[aaa],i);
			if(mapp.count(aaa^k)){
				int l=mapp[aaa^k]+1,r=i;
				arr[l]=min(arr[l],r);
			}
		}else{
			if(mapp.count(aaa^k)){
				int l=mapp[aaa^k]+1,r=i;
				arr[l]=min(arr[l],r);
			}
			mapp[aaa]=max(mapp[aaa],i);
		}
	}
	for(int i=n;i>=1;i--){
		if(arr[i]!=LLONG_MAX)dp[i][1]=max(dp[arr[i]+1][0],dp[arr[i]+1][1])+1;
		dp[i][0]=max(dp[i+1][0],dp[i+1][1]);
	}
	printf("%lld",max(dp[1][1],dp[1][0]));
	return 0;
}
