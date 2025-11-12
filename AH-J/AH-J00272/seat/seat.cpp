#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10000000],x,y;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int p=a[1],l;
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
		if(a[i]==p)
		{
			l=i;
			break;
		}
	if(l%n==0)
	{
		if(l/n%2==0)x=n;
		else x=1;
	}
	if(l%n!=0)
	{
		int w=l%n;
		int h=l/n+1;
		if(h%2==0)x=n-w+1;
		else x=w;
	}
	if(l%n==0)y=l/n;
	else y=l/n+1;
	cout<<y<<" "<<x;
	return 0;
}
