#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int dp[10010];
int a[5010];
int n;
int ans;
int main()
{
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin>>n;
for(int i=1;i<=n;i++){
	cin>>a[i];
	}
sort(a+1,a+n+1);
for(int i=0;i<=a[1];i++)
	dp[i]++;
for(int i=2;i<n;i++){
	int k=a[i];
	for(int j=a[i+1]+1;j>=1;j--){
		dp[j]=dp[j]+dp[max(j-k,0)];
		}
	dp[0]++;
	ans+=dp[a[i+1]+1];
	}
cout<<(ans+n)%mod;
return 0;
}
/*
while(true)
	cout<<"csp2025rp++!";
*/
