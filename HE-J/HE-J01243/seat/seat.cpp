#include<bits/stdc++.h>
using namespace std;
int n,m,z,a[10005],ans;
int hang,lie;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	z=a[1];
	sort(a+1,a+n*m+1);
	for (int i=n*m;i>=1;i--)
	{
		
		if (a[i]==z)
		{
			ans++;
			break;
		}
		ans++;
	}
	lie=(ans+n-1)/n;
	if (lie%2==1)
	{
		hang=(ans+n-1)%n+1;
	}
	else
	{
		hang=(n+1)-((ans+n-1)%n+1);
	}
	cout<<lie<<" "<<hang;
	return 0;
}
