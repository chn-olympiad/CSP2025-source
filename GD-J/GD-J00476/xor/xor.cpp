#include<bits/stdc++.h>
using namespace std;
const int maxn=1048576+10;
int a[maxn],sum[maxn],n,k,lst[maxn],f[maxn],dp[maxn],p=-1;
int main(){	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)sum[i]=(sum[i-1]^a[i]);
	memset(lst,-1,sizeof(lst)); 
	lst[sum[0]]=0;
	for(int i=1;i<=n;i++){
		int g=(sum[i]^k);
		if(lst[g]!=-1)f[i]=lst[g]+1;
		else f[i]=-1;
		lst[sum[i]]=i;
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k)p=max(p,i);
		p=max(p,f[i]);
		if(p!=-1)dp[i]=dp[p-1]+1;
		else dp[i]=0;
	}
	cout<<dp[n];
} 
