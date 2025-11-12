#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],tmp,ans,st;
bool vis[1000005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]^=a[i-1];
	}
	vis[0]=1;
	for(int i=1;i<=n;i++)
	{
		tmp=(k^a[i]);
		if(vis[tmp])
		{
			ans++;
			for(int j=st;j<i;j++) vis[a[j]]=0;
			st=i;
		}
		vis[a[i]]=1;
	}
	cout<<ans;
	return 0;
}
