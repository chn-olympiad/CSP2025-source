#include<bits/stdc++.h>
using namespace std;

const int N=500005;
int n,k,a[N],dp[N],x=0,v[N],t;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		v[++t]=a[i];
		for(int j=1;j<=t;j++){
			if(j!=t) v[j]^=a[i];
			if(v[j]==k){
				dp[i]=dp[x]+1;x=i;t=0;break;
			}
		}
		dp[i]=max(dp[i],dp[x]);
	}
	printf("%d",dp[n]);
	return 0;
}
