#include <bits/stdc++.h>
using namespace std;
long long n,m,a[105],R,num;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+n*m+1);
	int l=1,r=n*m;
	while (l<=r)
	{
		int mid=(l+r)/2;
		if (a[mid]<=R)
		{
			num=mid;
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	num=n*m-num+1;
	int f=0;
	if (num%n==0)
	{
		f=1;
		cout<<num/n<<" ";
	}
	else
	{
		f=2;
		cout<<num/n+1<<" ";
	}
	if (f==1)
	{
		if ((num/n)%2==0) cout<<1;
		else cout<<n;
	}
	else
	{
		if ((num/n+1)%2==0) cout<<n-(num%n)+1;
		else cout<<num%n;
	}
	return 0;
}
