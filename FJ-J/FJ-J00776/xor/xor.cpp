#include<bits/stdc++.h>
using namespace std;
int n;
long long k,a[500005],s[500005],dp[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]^a[i];
	}
	int p=0;
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		for(int j=p+1;j<=i;j++){
			if((s[i]^s[j-1])==k){
				dp[i]++;
				p=i;
				break;
			}
		}
	}
	cout<<dp[n];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
