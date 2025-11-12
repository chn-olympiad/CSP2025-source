#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,sticks[50005],ans=0,tmp[50005],vis[50005],sta=1;
void c(int m,int s)
{
	if(s>m)
	{
		int maxn=0,cnt=0;
		for(int i=1;i<=m;i++)
		{
			maxn=max(maxn,tmp[i]);
			cnt+=tmp[i];
		}
		if(2*maxn<cnt)
		{
			ans++;
			ans%=mod;
		}
	}
	for(int i=sta;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			tmp[s]=sticks[i];
			sta=i;
			c(m,s+1);
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>sticks[i];
	}
	for(int i=3;i<=n;i++)
	{
		c(i,1);
	}
	cout<<ans;
	return 0;
}
