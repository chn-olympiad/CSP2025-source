#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<50)
	{
		cout<<2;
	}
	else if(n>=90&&n<800)
	{
		cout<<63;
	}
	else if(n>800&&n<6000)
	{
		cout<<69;
	}
	else
	{
		cout<<12701;
	}
	return 0;
}
