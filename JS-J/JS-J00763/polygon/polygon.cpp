#include<bits/stdc++.h>
using namespace std;
int len[5010];
long long dp[10010];
bool gs[10000];
long long ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,i;
	cin>>n;
	for(i=1;i<=n;i++) 
	{
		cin>>len[i];
		dp[len[i]]++;
		gs[len[i]]=1;
	}
	sort(len+1,len+n+1);
	if(n==3)
	{
		if(len[1]+len[2]>len[3]&&len[2]+len[3]>len[1]&&len[3]+len[1]>len[2]) cout<<1;
		else cout<<0;
	}
	else 
	{
		long long ans=0;
		ans=((n-1)%998244353)*((n-2)%998244353)/2%998244353;
		cout<<ans;
	}
}
