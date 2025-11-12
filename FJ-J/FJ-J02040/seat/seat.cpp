#include<bits/stdc++.h>
using namespace std;
int n,m;
int s;
int a[111];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i(1); i<=n*m; i++)
	{
		cin>>a[i];
		if(a[i]>=a[1])
			s++;
	}
	if(n==1)
	{
		cout<<n<<" "<<1;
	}
	else if(m==1)
	{
		cout<<1<<" "<<n;
	}
	else if(s%n==0)
	{
		int k=ceil(s/n+0.5);
		if(k%2==0)
			cout<<k<<" "<<1;
		else
			cout<<k<<" "<<n;
	}
	else
	{
		int k=ceil(s/n+0.5);
		if(k%2==1)
		{
			cout<<k<<" "<<s%n;
		}
		else
		{
			int q=s%n;
			cout<<k<<" "<<n-q+1;
		}
	}
	return 0;
}

//2 2 99 100 97 98
