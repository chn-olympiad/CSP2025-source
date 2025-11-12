#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int ans;
bool v[500005];
int l[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==k)
		{
			ans++;
			v[i]=1;
		}
		
	}
	
	int cnt=0;
	if(k==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				cnt++;
			}
			
		}
		
		if(cnt==0)
		{
			cout<<n/2;
			return 0;
		}
		
		for(int i=1;i<=n-1;i++)
		{
			if(a[i]==1&&a[i+1]==1)
			{
				cnt++;
				i++;
			}
			
		}
		
		cout<<cnt;
		return 0;
	}
	
	if(k==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)
			{
				cnt++;
			}
			
		}
		
		cout<<cnt;
		return 0;
	}
	
	int maxn=0;
	for(int i=1;i<=n-1;i++)
	{
		if(v[i]==1)
		{
			continue;
		}
		
		int sum=a[i];
		for(int j=i+1;j<=n;j++)
		{
			if(v[j]==1)
			{
				sum=a[j+1];
				j++;
				continue;
			}
			
			sum=sum^a[j];
			if(sum==k)
			{
				l[i]++;
				sum=a[j+1];
				j++;
			}
			
		}
		
		maxn=max(maxn,l[i]);
	}
	
	cout<<maxn+ans;
	return 0;
}
