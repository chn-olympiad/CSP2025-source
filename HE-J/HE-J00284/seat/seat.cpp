#include<bits/stdc++.h>
using namespace std;
long long n,m,b;
long long l=0;
long long a[105],h;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	b=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(b==a[i])
		{
			l=i/n+1;
			if(l%2==1)
			{
				h=i-3*(l-1);
			}
			else
			{
				h=n-(i-n*(l-1)-1);
			}
			cout<<l<<" "<<h;
		}
	}
	return 0;
}
