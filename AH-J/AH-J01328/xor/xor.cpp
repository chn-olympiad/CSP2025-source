#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],c[500005],idx=0,s,s2,flag=1;
int check(int x,int y)
{
	int sum=0,i=1;
	while(1)
	{
		if(x==0&&y==0) break;
		if(x%2!=y%2) sum+=i;
		x/=2,y/=2,i*=2;
	}
	return sum;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0) s++;
		else if(a[i]==1) s2++;
		if(flag==1)
		{
			if(a[i]==0) flag=-1;
			else if(a[i]!=1) flag=0;
		}
		else if(flag==-1)
			if(a[i]!=0&&a[i]!=1) flag=0;
	}
	if(flag==1)
	{
		if(k==1) cout<<n;
		else if(k==0) cout<<n/2;
		else cout<<0;
		return 0;
	}
	else if(flag==-1)
	{
		if(k==1) cout<<s2;
		else if(k==0)
		{
			int ans=s,sum=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1) sum++;
				else
				{
					ans+=sum/2;
					sum=0;
				}
			}
			ans+=sum/2;
			cout<<ans;
		}
		else cout<<0;
		return 0;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		c[++idx]=a[i];
		if(c[idx]==k)
		{
			ans++;
			idx=0;
			memset(c,0,sizeof c);
		}
		else
		{
			for(int j=1;j<idx;j++)
			{
				c[j]=check(c[j],a[i]);
				if(c[j]==k)
				{
					ans++;
					idx=0;
					memset(c,0,sizeof c);
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
