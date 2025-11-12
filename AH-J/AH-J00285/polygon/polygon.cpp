#include <bits/stdc++.h>
using namespace std;
int n,a[5005],sum,maxn;
int main()
{
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++)
{
	cin>>a[i];
	sum+=a[i];
	}
	if(n<3)cout<<0;
	else 
	{
		sort(a+1,a+1+n);
		maxn=a[n];
		if(sum>maxn*2)cout<<1;
		else cout<<0;
	}
return 0;
}
