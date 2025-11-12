#include <bits/stdc++.h>
using namespace std;
int num;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n-2;i++)
	{
		for(int j=i+1;j<n-1;j++)
		{
			for(int k=j+1;k<n;k++)
			{
				if(a[i]+a[j]+a[k]>2*max(max(a[i],a[j]),a[k]))
				{
					num++;
				}
			}
		}
	}
	num*=3;
	num%=998244353;
	cout<<num;
	return 0;
}