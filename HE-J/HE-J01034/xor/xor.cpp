#include<bits/stdc++.h>
using namespace std;
int n,k,gs,manx=-10000;
int a[600000];
int rf(int cd)
{
	int sl=0;
	int ms=-10000;
	for(int i=1;i<=n;i++)
	{
		int x=a[i];
		for(int j=i+1;j<=i+cd-1;j++)
		{
			if(x==k)
			{
				sl++;
				ms=max(j+1-i,ms);
				i=j;
				break;
			}
			x^=a[j];
		}
	}
	if(sl>=manx&&ms<=cd) return 1;
	else return 0;
}
int rf1(int cd)
{
	int sl=0;
	int ms=-10000;
	for(int i=1;i<=n;i++)
	{
		int x=a[i];
		for(int j=i+1;j<=i+cd-1;j++)
		{
			if(x==k)
			{
				sl++;
				ms=max(j+1-i,ms);
				i=j;
				break;
			}
			x^=a[j];
		}
	}
	return sl;
}
int main()
{
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	int l=0,r=n;
	manx=rf1(n);
	while(l+1<r)
	{
		int mid=(l+r)/2;
		gs=n/mid;
		if(rf(mid)==1) 
		{
			manx=gs;
			r=mid;
		}
		else l=mid;
	}
	cout<<manx;
	return 0;
}
