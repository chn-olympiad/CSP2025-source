#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],cnt0,cnt1;
bool flag=1;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=0&&a[i]!=1)
		{
			flag=0;
		}
		if(a[i]==1)
		{
			cnt1++;
		}
		if(a[i]==0)
		{
			cnt0++;
		}
	}
	if(k==0&&flag)
	{
		cout<<cnt1/2+cnt0;
		return 0;
	}
	if(k==1&&flag)
	{
		cout<<cnt1;
	}
	return 0;
}
