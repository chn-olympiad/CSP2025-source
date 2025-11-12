#include<bits/stdc++.h>
using namespace std;
/*
maybe dp
*/
const int N=5e5+5;
int a[N];
int dp[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		int nowxor=0;
		for(int j=i;j>=1;j--){
			nowxor^=a[j];
			if(nowxor==k){
				dp[i]=max(dp[i],dp[j-1]+1);
				break;
			}
		}
	}
	cout<<dp[n]<<"\n";
}
