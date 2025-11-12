#include<bits/stdc++.h>
using namespace std;
long long a[10005];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long i,n,m;
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	long long r=a[1];
	sort(a+1,a+(n*m)+1);
	long long sl=0;
	for(i=n*m;i>=1;i--)
	{
		sl++;
		if(a[i]==r)
		{
			r=sl;
			break;
		}
	}
	long long lie,hang;
	if(r%n==0)
		lie=r/n;
	else
		lie=r/n+1;
	r=r%n;
	if(r==0)
		hang=n;
	else
		hang=r;
	if(lie%2==0)
		hang=n-hang+1;
	cout<<lie<<" "<<hang;
}
