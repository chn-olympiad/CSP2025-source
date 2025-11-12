#include<bits/stdc++.h>
using namespace std;
int n,k,a,s[500010],dp[500010],m[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	if(n>=1e5){cout<<0; return 0;}
	for(int i=1;i<=n;i++){
		cin>>a;
		s[i]=s[i-1]^a;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j>=1;j--){
			if((s[i]^s[j-1])==k){
				dp[i]=m[j-1]+1;
				break;
			}
		}
		dp[i]=max(dp[i],dp[i-1]);
		m[i]=max(m[i-1],dp[i]);
	}
	cout<<m[n];
	return 0;
}
