#include<bits/stdc++.h>
using namespace std;
int ans,n,k,t;
int a[500010],cnt,sum;
bool b[500010],flag=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			for(int l=i;l<=j;l++)
			{
				if(b[l]==0)
				{
					cnt=cnt^a[l];
					sum++;				
				}
				if(b[l]==1) break;
			}
			if(cnt==k&&sum==j-i+1)
			{
				ans++;
				for(int l=i;l<=j;l++)
					b[l]=1;
			}
			sum=0;cnt=0;flag=1;
		}
	}
	cout<<ans;
	return 0;
}
