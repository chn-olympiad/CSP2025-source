#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],xs,opt,lie,hang;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>xs;
	a[1]=xs;
	for (int i=2;i<=n*m;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n*m+1);
	for (int i=n*m;i>=1;i--)
	{
		if (a[i]==xs)
		{
			opt=n*m-i+1;
			break;
		}
	}
	lie=(opt-1)/n+1;
	printf("%d",lie);
	cout<<" ";
	hang=opt%n;
	if (hang==0)
	{
		if (lie%2==0)
		{
			cout<<1;
			return 0;
		}
		else
		{
			cout<<n;
			return 0;
		}
	}
	if (lie%2==0)
	{
		hang=n+1-hang;
	}
	printf("%d",hang);
}
