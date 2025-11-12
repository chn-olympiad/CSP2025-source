#include<bits/stdc++.h>
using namespace std;
int n,k,a[50005],flag1,flag10;
map<int,int> mp; 
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1) flag1=1; 
		if(a[i]!=1&&a[i]!=0) flag10=1;
	}
	if(!flag1&&k==0) cout<<n/3;
	else if(!flag1&&k==1) cout<<n/2;
	else if(!flag10)
	{
		int cnt=0;
		if(k==1)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1) cnt++,mp[i]=1;
			}
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1) continue;
				if(a[i]==0)
				{
					if(!mp[i]&&!mp[i+1]) 
					{
						cnt++;
						mp[i]=mp[i+1]=1;
					}
				}
			}
		}else
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==0) cnt++,mp[i]=1;
			}
			for(int i=1;i<=n;i++)
			{
				if(a[i]==0) continue;
				if(a[i]==1)
				{
					if(!mp[i]&&!mp[i+1]&&!mp[i+2]) 
					{
						cnt++;
						mp[i]=mp[i+1]=mp[i+2]=1;
					}
				}
			}
		} 
		cout<<cnt;
	}else
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==k) cnt++;
		}
		cout<<cnt;
	}
	return 0;
}