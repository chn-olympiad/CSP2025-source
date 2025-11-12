#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
ll n,m,a[500005],s[500005],dp[500005],k,cnt,sum;
bool flag,c,p;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]>1) flag=1;
		s[i]=s[i-1]^a[i];
		if(a[i]==k){
			dp[i]=1;
			cnt++;
		} 
	}
	if(!flag&&k<=1){
		if(k==0){
			for(int i=1;i<=n;++i){
				if(a[i]==1){
					sum++;
				}
				else{
					cnt+=sum/2;
					sum=0;
				}
			}
			cout<<cnt;
		}
		else{
			cout<<cnt;
		}
		exit(0);
	}
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			dp[j]=max(dp[j],dp[j-1]);
			if((s[j]^s[i-1])==k) dp[j]=max(dp[j],dp[i-1]+1);
		}
	}
	cout<<dp[n];
	return 0;
}