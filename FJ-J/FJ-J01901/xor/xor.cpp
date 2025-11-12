#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int n,a[N],mx[N],dp[N],k,ans,q[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	memset(mx,-0x3f3f3f3f,sizeof(mx));
	mx[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];a[i]^=a[i-1];
		dp[i]=max(mx[a[i]^k]+1,0);
		q[i]=max(q[i-1],dp[i]);
		mx[a[i]]=max(q[i],mx[a[i]]);
	}
	for(int i=1;i<=n;i++) ans=max(ans,dp[i]);
	cout<<ans<<' ';
	//for(int i=1;i<=n;i++) cout<<dp[i]<<' ';
 }
/*
4 0
2 1 0 3
*/
