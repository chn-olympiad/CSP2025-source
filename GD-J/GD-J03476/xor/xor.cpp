#include<bits/stdc++.h>
using namespace std;
bool b;
int f[500005],a[500005],dp[500005],m[500005],n,ma,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		f[i]=f[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int t=i;t>=1;t--){
			if((f[i-1]^f[t-1])==(k^a[i])){
				dp[i]=m[t-1]+1;
				break;
			}
		}
		m[i]=max(m[i-1],dp[i]);
	}
	cout<<m[n];
	
	return 0;
}
