#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[200005]={};
int a0,a1;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0)
		{
			a0++;
		}
		if(a[i]==1)
		{
			a1++;
		}
	}
	if(k==1)
	{
		cout<<a1;
	}else
	{
		cout<<a0;
	}
	return 0;
 } 