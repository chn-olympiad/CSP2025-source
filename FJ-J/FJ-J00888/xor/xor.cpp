#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],n,k,xo[N],dp[N],s[N];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		xo[i]=xo[i-1]^a[i];
    }
    dp[1]=(a[1]==k);
    s[a[1]]=1;
	for(int i=2;i<=n;i++){
		dp[i]=(xo[i]==k);
		dp[i]=max(dp[i-1]+(int)(a[i]==k),dp[i]);
		int p=xo[i]^k;
		if(s[p]!=0)dp[i]=max(dp[i],dp[s[p]]+1);
		if(s[xo[i]]==0||dp[i]>dp[s[xo[i]]])s[xo[i]]=i;
	}
	cout<<dp[n];
	return 0;
}
