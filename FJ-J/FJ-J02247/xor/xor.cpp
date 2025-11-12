#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	bool f=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1) f=1;
	}
	if(!f) 
	{
		if(n%2==0) cout<<n;
		else cout<<n-1;
	}
	return 0;
}
