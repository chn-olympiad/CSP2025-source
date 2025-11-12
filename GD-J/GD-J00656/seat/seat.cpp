#include<bits/stdc++.h>
using namespace std;
long long n,m,a[111],b;
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
	sort(a,a+n*m+1);
	for(int i=n*m;i>=1;i--)
	{	
		if(b==a[i])
		{
			cout<<(n*m-i)/n+1<<" "<<(n*m-i)%n+1;
			break;
		}	
	}
	return 0;
 } 
