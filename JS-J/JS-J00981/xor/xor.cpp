#include<bits/stdc++.h>
using namespace std;
int n,a[500005],dp[3000005],k,m,s,s1,c=1,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		s^=a[i];
		s1=s^k;
		if(dp[s1]==c or s1==0){
			s=0;
			c++;
			ans++;
		}
		dp[s]=c;
	}
	cout<<ans;
	return 0;
}
