#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,a[5030],sum=0;
long long p=0,q=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
		if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3])))cout<<1;
	else cout<<0;
	
	return 0;
}
