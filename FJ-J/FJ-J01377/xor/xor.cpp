#include<bits/stdc++.h> 
using namespace std;
int n,k,a[500001],ans=0,vis[2000001],sum[500001];
int main ()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int p=1;
	for (int i=1;i<=n;i++)
	{
	 	cin>>a[i];
	 	sum[i]=sum[i-1]^a[i];
	}
	vis[0]=1;
	for (int i=1;i<=n;i++)
	{
		int cnt=(sum[i]^sum[p-1])^k;
		if (vis[cnt]==1)
		{
			ans++;
			for (int j=p;j<=i;j++) vis[sum[j]^sum[p-1]]=0;
			p=i+1;
		}
		vis[sum[i]^sum[p-1]]=1;
	}
	cout<<ans<<endl;
	return 0;
}
