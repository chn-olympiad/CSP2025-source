#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=1<<20+5;
long long num[N],n,dp[N],c[M],k,ans;
int main(){
	freopen("xor2.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		num[i]=num[i]^num[i-1];
		long long t=k^num[i];
		if(c[t]||t==0){
			dp[i]=dp[c[t]]+1;
			ans=max(ans,dp[i]);
		}
		cout<<i<<" "<<c[num[i]]<<endl;
		c[num[i]]=i;
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

