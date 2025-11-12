#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005],dp[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(a[1]==k)dp[1]=1;
	for(int i=2;i<=n;i++){
		dp[i]=dp[i-1];
		int s=a[i];
		for(int j=i-1;j>=0;j--){
			if(dp[j]<dp[i-1])break;
			else if(s==k){
				dp[i]=dp[j]+1;
				break;
			}
			s^=a[j];
		}
	}
	cout<<dp[n];
	return 0;
}
/*
priority_queue<int> q;
bool operator<(SS x)
*/
