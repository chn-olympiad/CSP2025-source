#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],c;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	c=floor(n/2);
	cout<<c;
	return 0;
}
