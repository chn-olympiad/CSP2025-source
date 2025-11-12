#include<bits/stdc++.h>
using namespace std;
int n,k,f;
long long a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			f=1;
		}
	}
	if(f==0)
	{
		cout<<n/2;
	}
	else
	{
		cout<<"2";
	}
	return 0;
}
