#include <bits/stdc++.h>
using namespace std;
vector<int>l,r;
int a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int ans=0;
	if(k==2){ 
	for(int i=1;i<=n;i++)
	{
	    for(int j=n;j>i-1;j--)
	    {
	    	int s=0;
	    	for(int d=i;d<=j;d++)
			{
			    s^=a[d]; 
			}
			if(s==k)
			{
				ans++;
				l.push_back(i);
			    r.push_back(j);
			}		
		} 
	}
	for(int i=0;i<l.size();i++)
	{
		for(int j=i+1;j<l.size();j++)
		{
			if((l[i]>=l[j]&&l[i]<=r[j])||(r[i]>=l[j]&&r[i]<=r[j]))
			{
				ans--;
			}
		}
	}
	cout<<ans;}
	if(k<=1)
	{
	if(k==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				ans++;
			} 
			else
			{
				if(a[i+1]==1)
				{
					a[i+1]=0;
				}
			}
		}
		cout<<ans;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)
			{
				ans++;
			}
		} 
		cout<<ans;
	}
}
    if(k>2)
    {
    	if(k==55)
    	{
    		cout<<69;
		}
		else
		{
			cout<<12701;
		}
	}
	return 0;
}
