#include <bits/stdc++.h>
using namespace std;
int n,ans=0;
int a[5005];
void f(int sum,int maxx,int m,int count)
{
	if(sum>(maxx*2) && count>=3) ans=(ans+1)%998244353;
	for(int i=m;i<=n;i++)
	{
		f(sum+a[i],max(maxx,a[i]),i+1,count+1);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	f(0,0,1,0);
	cout<<ans;
	return 0;
}
