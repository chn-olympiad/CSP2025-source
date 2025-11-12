#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
int n,m,x,sco;
int a[1005];
int main()
{
	freopen("seat3.in","r",stdin);
	freopen("seat3.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==x)
		{
			sco=n*m-i+1;
			break;
		}
	}
	cout<<(sco+n-1)/n<<' ';
	if(((sco+n-1)/n)%2==1)
	{
		if(sco%n==0)
		{
			cout<<n;
		}
		else
		{
			cout<<sco%n;
		}
	}
	else
	{
		cout<<(n-sco%n)+1;
	}
	return 0;
}
