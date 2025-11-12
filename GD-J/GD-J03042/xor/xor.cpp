#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int dp[500005];
bool r=true;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		if(a[i]>1) {
			r=false;
		}
	}
	if(!r || k>1) {
		for(int i=1;i<=n;i++) {
			int num=0;
			dp[i]=dp[i-1];
			if(a[i]==k) {
				dp[i]++;
				continue;
			}
			for(int j=i;j>=1;j--) {
				num^=a[j];
				if(num==k) {
					dp[i]=max(dp[i],dp[j-1]+1);
					break;
				}
			}
		}
		cout<<dp[n];	
	}
	else {
		int ans=0;
		for(int i=1;i<=n;i++) {
			if(a[i]==k) {
				ans++;
			}
		}
		cout<<ans; 
	}
	return 0;
}
