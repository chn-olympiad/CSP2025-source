#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
ll a[5050],n,sum,dp[5050];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	sum=0;
	dp[n]=1;
	for(int i=n;i>=1;i--){
		for(int j=1;j<=n;j++){
			if(i>a[j]){
				dp[i-a[j]]++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		sum+=dp[a[i]];
	}
	cout<<sum%mod;
	return 0; 
}
