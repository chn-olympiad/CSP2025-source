#include<bits/stdc++.h>
using namespace std;
int a[5005],n,cnt;
int main()
{
	freopen("polgon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=3;i<=n;i++)
	{
		for(int j=1;i<=n;j++)
		{
			for(int k=1;k<=i;k++)
			{
				a[i]+=a[j];
			}
			if(a[i]>=max(a[i],max(a[i+1],a[i+2])))
			{
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
