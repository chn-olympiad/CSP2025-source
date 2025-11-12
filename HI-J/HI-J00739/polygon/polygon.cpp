#include<bits/stdc++.h>
using namespace std;
int n;
const int N=5010;
int a[N],mark[N],ans[N];
long long cnt;
const int mod=998244353;
void dfs(int k)
{
	if(k>=3)
	{
		int sum=0,mx=0;
		for(int i=0;i<k;i++)
		{
			sum+=a[ans[i]];
			mx=max(mx,a[ans[i]]);
		}
		if(sum>mx*2)
		{
			cnt++;
			cnt%=mod;
//			for(int i=0;i<k;i++)
//			{
//				cout<<ans[i]<<' ';
//			}
//			cout<<'\n';
		}
	}
	if(k==n)return;
	int last=0;
	if(k!=0)last=ans[k-1];
	for(int i=last;i<n;i++)
	{
		if(!mark[i])
		{
			mark[i]=1;
			ans[k]=i;
			dfs(k+1);
			mark[i]=0;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(n<30)
	dfs(0);
	else{
		for(int i=3;i<=n;i++)
		{
			long long now=1;
			for(int j=n;j>=n-i;j--)
			{
				now*=j;
				now%=mod;
			}
			for(int j=1;j<=i;j++)
			{
				now/=j;
			}
			cnt+=now;
			cnt%=mod;
		}
	}
	cout<<cnt;
	return 0;
}
