#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
const int LN=(1<<21)+5;
int a[N],q[N];
int zy[N];
int dp[N];
vector <int> t[LN];
int now[LN];
int tid[N];
int read()
{
	char ch=getchar();
	int x=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		x=x*10+(ch^48);
		ch=getchar();
	}
	return x;
}
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	n=read(),k=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	for(int i=n;i>=1;i--) 
	{
		q[i]=q[i+1]^a[i];
		t[q[i]].push_back(i);
		tid[i]=q[i];
	}
	int hz=k;
	for(int i=n;i>=1;i--)
	{
		if(now[hz]<t[hz].size())zy[i]=t[hz][now[hz]];
		hz^=a[i];
		now[tid[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		dp[i]=dp[i-1];
		if(zy[i]!=0) dp[i]=max(dp[i],dp[zy[i]-1]+1);
	}
	cout<<dp[n];
	return 0;
}