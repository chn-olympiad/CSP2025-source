#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	bool flag=true;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!+a[i-1])	flag=false;
	}
	if(flag==true)
	{
		if(a[1]==k)	cout<<n;
		else cout<<0;
		return 0;
	}
	return 0;
}
