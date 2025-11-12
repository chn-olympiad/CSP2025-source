#include <bits/stdc++.h>
using namespace std;
int n,m,xr,s=1;
int a[1005],b[1005];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int k=n*m;
	for(int i=1;i<=k;i++)
	{
		cin>>a[i];
		xr=a[1];
	}
	sort(a+1,a+k+1);
	for(int i=k;i>0;i--)
	{
		b[s]=a[i];
		if(b[s]==xr)
		{
			break;
		}
		s++;
	}
	if(s%n!=0)
	{
		cout<<s/n+1<<" ";
		if((s/n+1)%2==0)
		{
			cout<<n-s%n+1;
		}
		else
		{
			cout<<s%n;
		}
	}
	else
	{
		cout<<s/n<<" ";
		if((s/n)%2==0)
		{
			cout<<1;
		}
		else
		{
			cout<<n;
		}
	}
	
		
	
	return 0;
}
