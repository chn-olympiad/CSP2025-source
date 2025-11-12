#include<bits/stdc++.h>
using namespace std;
const int mOd=998244353;
int n,a[50000],ans;
void xuanqu(int x,int y,int s)
{
	if(x==0)
	{
		if(s>2*a[y-1])
		{
			ans=(ans+1)%mOd;
		}
		return;
	}
	for(int i=y;i<=n;i++)
	{
		xuanqu(x-1,i+1,s+a[i]);
	}
}
bool bdx(int x,int y)
{
	return x<y;
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
	sort(a+1,a+1+n,bdx);
	for(int i=3;i<=n;i++)
	{
		xuanqu(i,1,0);
	}
	cout<<ans;
	return 0;
}
