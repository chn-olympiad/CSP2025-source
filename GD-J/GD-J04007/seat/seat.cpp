#include<bits/stdc++.h>
using namespace std;
long long n,m,a[110],yyy,ip,pm,lie;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	ip=1;
	for(long long i=1;i<=n;i++)
	{
		for(long long j=1;j<=m;j++)
		{
			cin>>a[ip++];
		}
	}
	ip-=1;
	yyy=a[1];
	pm=1;
	sort(a+1,a+1+ip);
	for(long long i=ip;i>=1;i--)
	{
		if(a[i]==yyy)
		{
			pm=ip-i+1;
			break;
		}
	}
	lie=(pm+n-1)/n;
	pm=pm-(lie-1)*n;
	if(lie%2==1)
	{
		cout<<lie<<" "<<pm;	
	}
	else
	{
		cout<<lie<<" "<<n-pm+1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
