#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n*m+1],x;
    cin>>x;
    a[1]=x;

    for(int i=2;i<=n*m;i++)
    {
    	cin>>a[i];
	}
	sort(a+1,a+n*m+1);
	int z=0;
	for(int i=n*m;i>=1;i--)
	{
		if(a[i]==x)
		{
			z=n*m-i+1;
			break;
		}
	} 

	int i=z%n;
	if(((z-1)/n+1)%2==1)
	{
		
		cout<<((z-1)/n+1)<<" ";
		if(i==0) cout<<n;
		else cout<<z%n;
	}
	else
	{
		cout<<((z-1)/n+1)<<" ";
		if(i==0)
		{
			cout<<1;
		}
		else
		{
			cout<<n-i+1; 
		}
	}
    return 0;
}
