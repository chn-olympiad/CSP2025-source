#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,a[N],dp[N],s[N],b[(1<<20)+100],k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[i]=s[i-1]^a[i];
	}
	dp[0]=-0x3f3f3f3f;
	for(int i=n;i>=1;i--){
		if(a[i]==k){
			dp[i]=1;
		}
		dp[i]+=max(dp[i+1]+dp[i],dp[b[k^dp[i]]]+1);
		b[k^s[i]]=i;
	}
	cout<<dp[1];
	return 0;
}
