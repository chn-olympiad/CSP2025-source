#include<bits/stdc++.h>
using namespace std;
int a[555555],n,k;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool f = 1;
	for(int i = 1;i <= n;i ++)
	{
		cin>>a[i];
		if(a[i] != 1) f = 0;
	}
	if(k == 0 && f)
	{
		cout<<n/2;
	}
	return 0;
}
