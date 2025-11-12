#include <bits/stdc++.h>
using namespace std;
int n,m,a[789];
int b;
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
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
	{
		if(b==a[i])
		{
			b=i;
			break;	
		}
			
	}
	b=n*m-b+1;
	int p=(b-1)/n+1,q=b%n;
	if(q==0)
		q=n;
	cout<<p<<' ';
	if(p%2==0)
		cout<<n-q+1;
	else
		cout<<q;
		
	
	return 0;
}

