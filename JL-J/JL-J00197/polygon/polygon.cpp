#include <bits/stdc++.h>
using namespace std;
long long n,ans=0;
#define N 1000005
long long a[N];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==3)
	{
	for(int i=1;i<=n;i++)
	{
		a[i]++;
		ans++;
	}
	if(a[N]+=0)
	{
		cout<<"0"<<endl;
	}
}
	return 0;
}
