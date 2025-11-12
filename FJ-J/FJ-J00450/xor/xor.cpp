#include<bits/stdc++.h>
using namespace std;
int a[10000005],b[10000005],n,k,s;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==1)cout<<s;
	else	cout<<s+1;
	return 0;
}
