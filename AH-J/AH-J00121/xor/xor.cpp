#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N];
int s[N];
int n,k;
struct node{
	int l,r;
}t[N];
int dp[N];
void work()
{
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if((s[j]^s[i-1])==k)
			{
				t[++cnt]={i,j};
				break;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		dp[i]=1;
		for(int j=1;j<=i;j++)
		{
			if(t[j].r<t[i].l)dp[i]=max(dp[i],dp[j]+1);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans=max(dp[i],ans);
	}
	cout<<ans;
	return ;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>k;
	int ok=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=0&&a[i]!=1)ok=0;
	}
	s[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		s[i]=(s[i-1]^a[i]);
	}
	if(ok)
	{
		if(k==1)
		{
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1)ans++;
			}
			cout<<ans;
			return 0;
		}
		else if(k==0)
		{
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]==0)ans++;
			}
			for(int i=1;i<n;i++)
			{
				if(a[i]==a[i+1]&&a[i]==1)
				{
					ans++;
					i++;
				}
			}
			cout<<ans;
			return 0;
		}
	}
	if(n<=1000)
	{
		work();
		return 0;
	}
	
	int i=1,j=2;
	int ans=0;
	if(s[i]==k)
	{
		ans++;
		i++;
	}
	while(j<=n)
	{
		if((s[j]^s[i-1])==k)
		{
			ans++;
			j++;
			i=j;
		}
		else j++;
	}
	cout<<ans;
	return 0;
}
/*
4 3
2 1 0 3
*/
