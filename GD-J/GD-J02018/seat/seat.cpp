#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105],r,wz;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(i==1)r=a[i];
	}
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--)
	{
		wz++;
		if(a[i]==r)
		{
			break;
		}
	}
	cout<<bool(wz%n)+wz/n<<' ';
	if((bool(wz%n)+wz/n)%2==0)
	{
		long long h=wz%n;
		if(n==0)
		{
			cout<<"1";
		}
		else
		{
			cout<<n-h+1;
		}
	}
	else
	{
		long long h=wz%n;
		if(h==0)
		{
			cout<<n;
		}
		else
		{
			cout<<h;
		}
	}
	return 0;
}

