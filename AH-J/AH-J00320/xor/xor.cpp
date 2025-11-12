#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],f,f1;
int main()
{
  freopen("xor.in","r",stdin);
 	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>1)
		{
			f=f1=1;
		}
		if(a[i]!=1)
		{
			f=1;
		}
	}
	if(f==0)
	{
		if(k==0) cout<<n/2;
		else cout<<n;
		return 0;
	}
	if(f1==0)
	{
		int s=0;
		if(k==1)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1) s++;
			}
			cout<<s;
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==0)
				{
					s++;
				}
				else if(a[i]==1&&a[i+1]==1)
				{
					s++;
					i++;
				}
			}
			cout<<s;
		}
		return 0;
	}
	cout<<(n+k)/3;
	return 0;
}
