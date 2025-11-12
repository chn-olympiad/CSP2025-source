#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k;
int a[N],dp[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		dp[i]=(dp[i-1]^a[i]);
	}int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int cnt=dp[j]^dp[i-1];
			if(cnt==k) ans++;
		}
	}printf("%d",ans);
	return 0;
}

