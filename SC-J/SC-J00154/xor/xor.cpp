#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans,x=1,s[30],z,dp[500005];
bool b1=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1)b1=0;
	}for(int i=1;i<=n;i++){
		for(int j=x;j<=i;j++){
			dp[j]^=a[i];
			if(dp[j]==m){
				ans++;
				x=i+1;
				break;
			}
		}
	}cout<<ans;
	return 0;
}