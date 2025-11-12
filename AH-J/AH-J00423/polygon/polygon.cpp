#include<bits/stdc++.h>
using namespace std;
long long a[5010];
long long n,s,maxn;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s+=a[i];
		maxn=max(maxn,a[i]);
	}
	if(s>2*maxn)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
