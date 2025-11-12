#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[2000005];
int cnt1,cnt2;
int cnt;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(k==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)
			{
				cnt1++;
			}
			else if(a[i]==0)
			{
				cnt2++;
			}
		}
		cout<<cnt1/2+cnt2;
	}
	else if(k==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)
			{
				cnt1++;
			}
			else if(a[i]==0)
			{
				cnt2++;
			}
		}
		cout<<cnt1;
	}
	return 0;
}
