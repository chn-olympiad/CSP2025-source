#include<bits/stdc++.h>
using namespace std;
int a[500010],pre[500010],l[500010],lst[1100000],dp[500010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	lst[0]=-1;//标记一下 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=pre[i-1]^a[i];
		l[i]=lst[pre[i]^k];
		lst[pre[i]]=i;
//		cout<<pre[i]<<' '<<l[i]<<'\n';	
	}
	for(int i=1;i<=n;i++){
		if(l[i]==0){
			dp[i]=dp[i-1];
			continue;
		}
		if(l[i]==-1)l[i]=0;
		dp[i]=max(dp[i-1],dp[l[i]]+1);
	}
	cout<<dp[n];
	return 0;
}

