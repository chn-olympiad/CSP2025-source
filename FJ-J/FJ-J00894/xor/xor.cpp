#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],ans,a0,a1;
bool flog=1,b[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]==1)
		{
			ans++;
			b[i]=1;
		}
		if(a[i]==0)
		{ 
			a0++;
			flog=0;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]==1)
		{
			if(b[i]==1&&b[i+1]==1)
			{
				a1++;
				b[i]=0;
				b[i+1]=0;
			}
		}
	}
	if(flog==0)
	{
		if(k==1)
		{
			cout<<ans;
		}
		else if(k==0)
		{
			if(ans/2>=a0)
			{
				cout<<ans/2;
			}
			else
			{
				cout<<a0+a1;
			}
		}
	}
	else
	{
		if(k==1)
		{
			cout<<ans;
		}
		else if(k==0)
		{
			cout<<ans/2;
		}
	}
	return 0;
}
