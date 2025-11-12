#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m+1];
	for(int i=1;i<n*m+1;i++)cin>>a[i];
	int b=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m+1;i>=1;i--)
	{
		if(a[i]==b)
		{
			cout<<ceil((n*m-i+1)*1.0/n)<<' ';
			if((int)ceil((n*m-i+1)*1.0/n)%2!=0)
			{
				if((n*m-i+1)%n==0)cout<<n;
				else cout<<(n*m-i+1)%n;
			}
			else 
			{
				if((n*m-i+1)%n==0)cout<<0;
				else cout<<n-(n*m-i+1)%n+1;
			}
		}
	}
	return 0;
} 
