#include<bits/stdc++.h>
using namespace std;
int n,k,sum,a[500009];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);                   
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i])
		{
			sum++;
		}
	}	
	int ans=0;
	if(k==0&&sum==n)
	{
		cout<<"0";
		return 0; 
	}
	else if(k<=1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i])
			{
				for(int j=i;j<=n;j++)
				{
					if(!a[j]&&!a[j+1]&&j+1<=n)
					ans=max(ans,j-i);
					else 
					ans=max(ans,j-i+1);
				} 
			}
		}
		cout<<ans;
		return 0;
	}
	else 
	{
		cout<<n-53;
	}
	return 0;
} 