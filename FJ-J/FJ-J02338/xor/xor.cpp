#include<bits/stdc++.h>
using namespace std;
int n,k,i,a[500001];
long long xgm=1;
int main()
{
//	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i=i+1)
	{
		cin>>a[i];
		xgm=xgm*a[i];
	}
	if(xgm==1)
	{
		if(k==0)
		{
			cout<<n/2;
		}
	}
	return 0;
}

