#include<bits/stdc++.h>
using namespace std;
const int N=5e5+3,M=1e6+1e5;
int n,k;
int a[N],cnt[M];
int ansans=-INT_MAX,dp[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<M;i++){
		cnt[i]=-1;
	}
	cnt[0]=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]=(a[i]^a[i-1]);
		int now=(a[i]^k);
		int l;
		if(k==(a[i]^a[i-1])){
			l=i;
		}else{
			l=cnt[now];
		}
		if(l!=-1)dp[i]=max(dp[l-1]+1,dp[i]);
		dp[i]=max(dp[i-1],dp[i]);
		cnt[a[i]]=i+1;
	}
	cout<<dp[n];
	return 0;
}
