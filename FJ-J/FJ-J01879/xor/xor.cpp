#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int count_0=0;
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
			count_0++;			
		}
	}
	if(count_0==n)
	{
		cout<<0;
		return 0;
	} 
	cout<<1;
	return 0;
}
