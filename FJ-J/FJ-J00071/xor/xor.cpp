#include<bits/stdc++.h>
using namespace std;
int n,l,a[10005],t,k=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>l;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0)
		{
			k=0;
		}
	}
	if(k==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==l)
			{
				t++;
			}
		}
		cout<<t;
	}
	else if(l==0)
	{
		cout<<"0";
	}
	else
	{
		cout<<t;
	}
}
