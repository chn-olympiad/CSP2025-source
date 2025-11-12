#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N],dp[N];
int n,k;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int lst=0;
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		int res=0;
		for(int j=i;j>=lst+1;j--){
			res^=a[j];
			if(res==k){
				dp[i]=max(dp[i],dp[j-1]+1);
				lst=i;
				break;
			}
		}
	}
	cout<<dp[n];
	return 0;
}
