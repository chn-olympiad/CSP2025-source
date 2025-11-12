#include<bits/stdc++.h> 
using namespace std;
int a[121];
int n,m,r;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	r=a[1];
	sort(a,a+n*m+1);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==r)
		{
			if(n*m-i!=0)
			{
			int d=n*m-i+1;
			float x=n*m-i+1;
			int c=ceil(x/n);
			cout<<c<<" ";
			if(c%2==0)cout<<n-d%n+1;
			if(c%2==1)
			{
				if(d%n!=0)
					cout<<d%n+1; 
				else
					cout<<n; 
			}
			break;
			}
			else
				cout<<1<<" "<<1;
		}	
	}
	return 0;
}
