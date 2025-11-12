#include<bits/stdc++.h>
using namespace std;
long long a[5008],b[5008];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int x=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]>x)
		x=a[i];
	}
	unsigned long long ans=0;
	if(n==3)
	{
		int maxa=max(a[0],max(a[1],a[2]));
		if(a[0]+a[1]+a[2]>2*maxa)
		cout<<1;
		else
		cout<<0;
	}
	else if(x==1)
	{
		ans=1;
		for(int i=0;i<n;i++)
		{
			ans*=2;
			ans%=998244353;
		}
		int h=(n*(n-1))/2;
		ans-=h;
		ans-=n;
		ans--;
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
}
