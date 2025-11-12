#include<bits/stdc++.h>
using namespace std;

int a[500005],sum[500005];
int n,k,ans=0,avp=1;
int tot0=0,tot1=0;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int f1=1,f2=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==k)
		{
			ans++;
			avp=i+1;
		}
		sum[i]=a[i];
		for(int j=avp;j<=i-1;j++)
		{
			sum[j]=sum[j]^a[i];
			if(sum[j]==k)
			{
				ans++;
				avp=i+1;
				break;
			}
		}
		if(a[i]>1)
			f1=0;
		if(a[i]==0)
			tot0++;
		if(a[i]==1)
		{
			tot1++;
			if(f2==0)
				f2=1;
			else
			{
				f2=0;
				tot0++;
			}
		}
		else
			f2=0;
	}
	if(f1==true && k==0)
	{
		cout<<tot0;
		return 0;
	}
	if(f1==true && k==1)
	{
		cout<<tot1;
		return 0;
	}
	cout<<ans;
	return 0;
}