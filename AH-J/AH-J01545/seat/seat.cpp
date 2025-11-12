#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int c=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
		if(a[i]>a[0])
		{
			c++;
		}
	}
	if(c%n==0)
	{
		cout<<c/n<<" "<<n;
	}
	else
	{
		cout<<c/n+1<<" "<<c-n*(c/n);
	}
	return 0;	
}
