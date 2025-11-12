#include<bits/stdc++.h>
using namespace std;
int n,k,i,a[500001],o_ge;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++)
	cin>>a[i];
	if(k==0)
	{
		for(i=1;i<=n;i++)
		{
		    if(a[i]==0)
		    o_ge++;
		}
		cout<<o_ge;
		return 0;
	}
}
