#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int a[500005];
int b[500005];
bool vis[1<<23];
int c[1<<23],cnt=1;
set<int>st;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		b[i]=b[i-1]^a[i];
	}
	c[1]=0;
	vis[0]=true;
	for(int i=1;i<=n;i++)
	{
		if(vis[b[i]^k])
		{
			ans++;
			for(int j=1;j<=cnt;j++)
			{
				vis[c[j]]=false;
			}
			cnt=0;
		}
		if(!vis[b[i]])
		{
			vis[b[i]]=true;
			c[++cnt]=b[i];
		}
	}
	cout<<ans;
	return 0;
}
/*
4 2
2 1 0 3
* 
4 3
2 1 0 3
* 
4 0
2 1 0 3
*/
