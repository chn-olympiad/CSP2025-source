#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans[500005][2];
bool flag;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0) flag=true;
	}
	if(k==0&&!flag)
	{
		cout<<n;
		return 0;
	}
	if(k<=1)
	{
		if(k==0)
		{
			cout<<n;
		}
		else
		{
			if(!flag)
			{
				cout<<n/3;
			}
			else
			{
				
			}
		}
	}
	for(int i=1;i<=n;i++)//区间左端点 
	{
		for(int j=i;j<=n;j++)//区间右端点
		{
			 
		}
	}
	return 0;
}

